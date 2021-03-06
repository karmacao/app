/***********************************************************
 * Copyright: zhaodongwei@nanjing university
 * author: zhaodongwei(joodaw@gmail.com)
 * 
 * file: conf_struct.h
 * date: 2012-11-18
 * desc: conf struct declare
 ***********************************************************/

#ifndef _CONF_STRUCT_H_
#define _CONF_STRUCT_H_

#include <stdio.h>
#include <list>
#include <string>

#include "conf_nodetype.h"

namespace configure {

class ConfStruct {
public:
	ConfStruct();
	ConfStruct(const char* key, const char* value);
	ConfStruct(nodetype node);
	ConfStruct(const std::string& key, const std::string& value);
	~ConfStruct();

	std::string get_key() const {
		return _key;
	};
	void set_key(const char* key_in) {
		_key.clear();
		_key.append(key_in);
	}
	void set_key(const std::string& key) {
		_key.clear();
		_key.append(key);
	}

	std::string get_value() const {
		return _value;
	};
	void set_value(const char* value_in) {
		_value.clear();
		_value.append(value_in);
	}
	void set_value(const std::string& value) {
		_value.clear();
		_value.append(value);
	}
	
	ConfStruct* get_child() const {
		return _child;
	};
	ConfStruct* set_child(ConfStruct* p_child) {
		_child = p_child;
		return p_child;
	};

	ConfStruct* get_brother() const {
		return _brother;
	};
	ConfStruct* set_brother(ConfStruct* p_brother) {
		_brother = p_brother;
		return p_brother;
	};
	
	ConfStruct* get_elder_brother() {
		return _elder_brother;
	};

	ConfStruct* get_father() const {
		return _father;
	};
	ConfStruct* set_father(ConfStruct* p_father) {
		_father = p_father;
		return p_father;
	};

	nodetype get_nodetype() {
		return _node;
	};
	nodetype set_nodetype(nodetype node_in) {
		_node = node_in;
		return node_in;
	};

	int set_shadow(ConfStruct* src) {
		if (NULL == src) {
			return -1;
		}
		_shadow = src;
		return 0;
	};
	ConfStruct* get_shadow() {
		return _shadow;
	};

	bool add_to_tree();
	ConfStruct* get_last_child() const;
	
	int to_int();
	double to_double();
	std::string to_string();
	const char* to_cstr();

	int size();
	int save(FILE* new_fs, int depth);
	bool has_key(const char* key);
	bool has_key(const std::string& key);
	bool has_key(int key);

	ConfStruct& operator[](const char* key);
	ConfStruct& operator[](int key);

private:
	std::string _key;
	std::string _value;
	nodetype _node;
	ConfStruct* _child;
	ConfStruct* _brother;
	ConfStruct* _elder_brother;
	ConfStruct* _father;
	ConfStruct* _shadow;
	int init();
	
	bool _is_number(char letter) {
		if (letter >= '0' && letter <= '9') {
			return true;
		}
		return false;
	};
	double _get_number(std::string& str, int& iter);
	double _parse_number();
};

typedef ConfStruct conf_item;

};

#endif //#ifndef _CONF_STRUCT_H_

