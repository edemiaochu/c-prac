#include<iostream>
#include<vector>
#include<filesystem>
#include<string>
#include<regex>
int partion(int* arr, int left, int right) {
	int i = left, j = right, base = arr[left];
	while (i<j && arr[j]>base) --j;
	if (i < j) {
		std::swap(arr[i++], arr[j]);
	}
	while (i < j && arr[i] <= base) ++i;
	if (i < j) std::swap(arr[i], arr[j--]);
	return i;

}
void QuickSort(int* arr, int left, int right) {
	int middle;
	if (left < right) {
		middle = partion(arr, left, right);
	    QuickSort(arr, middle+1, right);
		QuickSort(arr, left, middle-1);
	}
}
void FindFile(std::string path) {
	for (auto s : std::filesystem::directory_iterator(path)) {
		std::string filename = s.path().filename().string();
		int i = 0;
		std::string changename = "lk_" + std::to_string(i);
		++i;
		std::cout << filename<<std::endl;
		//rename(filename.c_str(), changename.c_str());
	}
}

int main(int argc, char** argv) {
	std::string path = "F:\\photos\\12";
	std::string s = "This world will be better!";
	std::regex word_regex("(\\w+)");
	auto words_begin = std::sregex_iterator(s.begin(), s.end(), word_regex);
	auto words_end = std::sregex_iterator();
	for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
		std::smatch match = *i;
		std::string match_str = match.str();
		std::cout << match_str << '\n';
	}

	int arr[]{ 3,2,1,5,4,23,34,56,2,5,345,6,76,236567,765,8,67723,2234,234 };
	std::cout << sizeof(arr)/4;
	std::cout << std::endl;
	for (auto s : arr) std::cout << s<<",";
	std::cout << std::endl;
	QuickSort(arr, 0,sizeof(arr)/4-1);
	for (auto s : arr) std::cout << s<<",";
	std::cout << std::endl;
	return 0;
}