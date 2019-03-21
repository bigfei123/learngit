 /// @file    io1.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-10 21:12:47
 ///

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::vector;


//文件输入流
void test0()
{
	ifstream ifs;
	ifs.open("io1.cc");//对于文件输入流而言，打开的文件必须存在
	if(!ifs.good()){
		cout << "ifstrem open file error!" << endl;
		return ;
	}
	vector<string> lines;
	string str;
	//while(ifs >> str){ //输入流运算符用空格进行分隔
	while(getline(ifs, str)){
		//cout << str << endl;
		lines.push_back(str);
	}
	for(size_t idx =0; idx !=lines.size(); ++idx)
	{
	 	cout << lines[idx] << endl;	
	}
	cout <<" lines.size()= " << lines.size() << endl;
	ifs.close();
}

//文件输出流
void test1()
{
	ifstream ifs("io1.cc");
	//ifstream ifs("io1.cc",std::ios::in |std::ios::ate);//1438
	if(!ifs.good()) {
		cout << "ifstream open file error!" << endl;
		return ;
	}
	cout << " >> pos = " << ifs.tellg() << endl; //0
	ifs.seekg(0, std::ios::end);
	cout << " >> pos = " << ifs.tellg() << endl; //1438
	
	string file("test.txt");//如果文件不存在，则创建该文件,如果文件已经存在，
							//则直接清空文件重新写入内容
	ofstream ofs(file);
	if(!ofs) {
		cout << "ofstream open error!" << endl;
		ifs.close();//如果输出流打开失败，把输入流关掉
	}

	string line;
	while(getline(ifs, line)) {
			ofs << line << '\n';
	}		
	ofs.close();	

}


void printStreamStatus(fstream & fs)
{
	cout << "fs's badbit = " <<fs .bad() << endl
		 << "fs's failbit= " <<fs .fail() << endl
		 << "fs's eofbit = " <<fs .eof() << endl
		 << "fs's goodbit= " <<fs .good() << endl;
}
//从终端读入10个元素存入文件，再通过输出流输出 、文件输入输出流
void test2()
{
	//需要先创建test2.txt文件
	string file("test2.txt");
	fstream fs(file); 
	if(!fs)
	{
		cout << "fstream open file " << file << " error!" << endl;
		return ;
	}
	int number =0;
	for(size_t idx=0; idx!= 9; ++idx){
		std::cin>>number;

		fs << number << " "; //文件输出流的功能
	}
	cout << ">>> 查看流fs的状态："<<endl;
	printStreamStatus(fs);	
	cout << endl;
	size_t pos= fs.tellg();
	cout << " pos = " << pos << endl;

	//通过输出流的状态我们可以看到流的状态已由goodbit转为failbit
	//因为流的游标已到达末尾，此时输出的始终是末尾的数字。
	//要通过游标偏移seekg的方法使游标指向开始位置
	//fs.seekg(0);  //绝对位置
	fs.seekg(0, std::ios::beg);//相对位置
	for(size_t idx= 0; idx!= 9;++idx)
	{
		fs >> number ;     //文件输入流的功能
		cout << number << " " ;
	}
	cout<< endl;
	printStreamStatus(fs);
	fs.close();
} 

//若源文件存在则继续外后写，而不清空源文件
void test3()
{
	ifstream ifs("io1.cc");
	if(!ifs.good()) {
		cout << "ifstream open file error!" << endl;
		return ;

	}

	string file("test.txt");//如果文件不存在，则创建该文件,如果文件已经存在，
							//则直接清空文件重新写入内容
	ofstream ofs(file,std::ios::app); //app模式针对输入流而言
	if(!ofs) {
		cout << "ofstream open error!" << endl;
		ifs.close();//如果输出流打开失败，把输入流关掉
	}
	cout << "pos = " << ofs.tellp() << endl;
	ofs << "this is a new line\n";
	ofs.close();
}


int main(void)
{
	//test0();
	//test1();
	//test2();
	test3();
	return 0;
}
