#include <future>
#include <iostream>
using namespace std;

int main() {
	atomic_int times = 0;

	//async�и���std::async�ķ���ֵfutrue���������������ȴ��������
	//���ֱ��ʹ��async��Ϊһ����ʱ���������ֱ�ӵ�����ʱ������Ҫ�ȴ��������
	//�����ͬ��
	async(std::launch::async,
		[&] {
		while (times < 20) {
			std::cout << times++ << "......temp!" << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	});


	{
		//����Ҳ�ᵼ��ͬ��
		auto&& temp = async(std::launch::async,
			[&] {
			while (times < 30) {
				std::cout << times++ << "......next temp!" << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
		});
	}

	//std::launch::async �����������߳�
	auto&& a = async(std::launch::async,
	[&] {
		while (true) {
			std::cout << times++ << "......a!"<<std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	});

	//std::launch::deferred �ڵ���wait��get��ʱ��Ż������߳�(ͬ��)
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