#pragma once
#ifndef _API_H
#define _API_H
#include "Glob_Var.h"
#include "Intepretor.h"
#include "Record_Manager.h"
#include "Attributes.h"
#include "Buffer.h"
#include "Catalog.h"
#include "Select.h"
#include <string>
#include <vector>
#include <queue>
using namespace std;

/*
	负责调度各种模块.
	接受用户的输入，交由Interpreter处理，通过处理结果，调用
	各个模块的功能实现用户的需求.
*/
class API
{
public:
	API();
	static API & Instance();	//实例化
	/*
		命令操作
		*/
	void CreateTable(string & Tablename, vector<Attributes> & Attributes);						//Create		创建数据表
	void Select(queue<string> attributes, queue<string>tablelists,queue<string> wherelists);//Select 选择元组
	void Insert_Into(string &Tablename, vector<Tuple> Tuple_Lists);								//Insert into	插入元组
	void FixIndex(Table & table, vector<pair<Tuple, int>> tuple);								//修复index 索引
};
inline static API & Instance()
{
	static API API_Instance;
	return API_Instance;
}
#endif