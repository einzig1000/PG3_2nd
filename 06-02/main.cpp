#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <thread>
#include <mutex>
#include <condition_variable>

class MapLoader
{
public:
    // 読み込み開始（非同期）
    void loadThread(const std::string& filename)
    {
        th = std::thread(&MapLoader::load, this, filename);
    }

	// 読み込み完了確認
    bool isLoaded()
    {
        std::lock_guard<std::mutex> lock(mtx);
        return loaded;
	}

    // 読み込み完了を待つ
    void wait()
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&] { return loaded; });
    }

    // 読み込んだマップを取得
    std::vector<std::vector<int>> getMap()
    {
        std::lock_guard<std::mutex> lock(mtx);
        return mapData;
    }

    // スレッド終了待ち
    void join()
    {
        if (th.joinable())
            th.join();
    }

private:
	// 共有データの管理変数
    std::thread th;
    std::mutex mtx;
    std::condition_variable cv;

	// 共有データ
    bool loaded = false;
    std::vector<std::vector<int>> mapData;

	// マップ読み込み
    void load(const std::string& filename)
    {
        std::vector<std::vector<int>> temp;

        std::ifstream ifs(filename);
        if (!ifs)
        {
            std::lock_guard<std::mutex> lock(mtx);
            loaded = true;
            cv.notify_all();
            return;
        }

        std::string line;
        while (std::getline(ifs, line))
        {
            std::vector<int> row;
            std::stringstream ss(line);
            std::string cell;

            while (std::getline(ss, cell, ','))
            {
                if (!cell.empty())
                    row.push_back(std::stoi(cell));
            }

            if (!row.empty())
                temp.push_back(std::move(row));
        }

		// 読み込み完了を通知
        {
            std::lock_guard<std::mutex> lock(mtx);
            mapData = std::move(temp);
            loaded = true;
        }
        cv.notify_all();
    }
};

// マップ描画
void drawMap(const std::vector<std::vector<int>>& map)
{
    for (const auto& row : map)
    {
        for (int v : row)
            std::cout << (v == 0 ? "□" : "■");
        std::cout << "\n";
    }
}

int main()
{
    MapLoader loader;

    // マップをバックグラウンドで読み込み開始
    loader.loadThread("map.csv");

	// 読み込み完了までローディング表示
    const char* dots[] = { ".  ", ".. ", "..." };
    int idx = 0;

    while (!loader.isLoaded())
    {
        std::cout << "\r読み込み中" << dots[idx] << std::flush;
        idx = (idx + 1) % 3;

        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }


    std::cout << "\r読み込み完了！   \n";


    // マップ取得
    auto map = loader.getMap();

	// スレッド終了待ち
    loader.join();

    if (map.empty())
    {
        std::cout << "マップ読み込み失敗\n";
        return 0;
    }

    std::cout << "マップ読み込み完了\n\n";
    drawMap(map);

    return 0;
}