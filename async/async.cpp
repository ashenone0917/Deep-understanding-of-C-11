#include <future>
#include <iostream>
using namespace std;

int main() {
	atomic_int times = 0;

	//async有个坑std::async的返回值futrue会在析构函数里会等待任务完成
	//如果直接使用async作为一个临时变量，则会直接导致临时变量需要等待任务完成
	//而变成同步
	async(std::launch::async,
		[&] {
		while (times < 20) {
			std::cout << times++ << "......temp!" << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	});


	{
		//这样也会导致同步
		auto&& temp = async(std::launch::async,
			[&] {
			while (times < 30) {
				std::cout << times++ << "......next temp!" << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
		});
	}

	//std::launch::async 会立即启用线程
	auto&& a = async(std::launch::async,
	[&] {
		while (true) {
			std::cout << times++ << "......a!"<<std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	});

	//std::launch::deferred 在调用wait或get的时候才会启用线程(同步)
	auto&& b = async(std::launch::deferred,
		[&] {
		while (true) {
			std::cout << times++ << "......b!"<<std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	});

	std::this_thread::sleep_for(std::chrono::seconds(5));
	b.wait();
}