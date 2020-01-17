//
// Created by amitnir29 on 10/12/2019.
//

#ifndef MITKADEM2_EX2_H
#define MITKADEM2_EX2_H

#include <string>
#include <list>
#include <unordered_map>
#include <fstream>
#include <functional>

using namespace std;
template <typename T>
class CacheManager
{
    int capacity = 0;
    list <string> names;
    unordered_map <string, pair <T, list <string>::iterator>> map;

public:
    CacheManager(int cap) {
        capacity = cap;
    }

    void insert(string key, T obj) {
        auto exist = map.find(key + T::class_name);
        if (exist != map.end()) {
            map.erase(key + T::class_name);
            names.remove(key + T::class_name);
            names.push_front(key + T::class_name);
            map.insert({key + T::class_name, pair <T, list <string>::iterator>(obj, names.begin())});
        } else {
            if (names.size() == capacity) {
                string del = names.back();
                names.pop_back();
                names.push_front(key + T::class_name);
                map.erase(del);
                map.insert({key + T::class_name, pair <T, list <string>::iterator>(obj, names.begin())});
            } else {
                names.push_front(key + T::class_name);
                map.insert({key + T::class_name, pair <T, list <string>::iterator>(obj, names.begin())});
            }
        }

        std::ofstream file(key + T::class_name, std::ofstream::binary);
        file.write((char *) &obj, sizeof(obj));
        if (file.bad()) {
            throw "file failed";
        }
        file.close();
    }

    T get(string key) {
        /*auto exist = map.find(key + T::class_name);
        if (exist != map.end()) {
            names.remove(key + T::class_name);
            names.push_front(key + T::class_name);
            map.at(key + T::class_name).second = names.begin();
            return map.at(key + T::class_name).first;
        } else {
            ifstream ifile(key + T::class_name);
            if (ifile) {
                std::ifstream file(key + T::class_name, std::ofstream::binary);
                T obj;
                file.read((char *) &obj, sizeof(obj));
                if (file.bad()) {
                    throw "file failed";
                }
                file.close();
        }*/
        auto exist = map.find(key + T::class_name);
        if (exist != map.end()) {
            names.remove(key + T::class_name);
            names.push_front(key + T::class_name);
            map.at(key + T::class_name).second = names.begin();
            return map.at(key + T::class_name).first;
        } else {
            ifstream ifile(key + T::class_name);
            if (ifile) {
                std::ifstream file(key + T::class_name, std::ofstream::binary);
                T obj;
                file.read((char *) &obj, sizeof(obj));
                if (file.bad()) {
                    throw "file failed";
                }
                file.close();
                if (names.size() == capacity) {
                    string del = names.back();
                    names.pop_back();
                    names.push_front(key + T::class_name);
                    map.erase(del);
                    map.insert({key + T::class_name, pair <T, list <string>::iterator>(obj, names.begin())});
                } else {
                    names.push_front(key + T::class_name);
                    map.insert({key + T::class_name, pair <T, list <string>::iterator>(obj, names.begin())});
                }
                return obj;
            } else {
                throw "key does not exist";
            }
        }
    }

    void foreach(function<void(T &)> f) {
        for (string s: names) {
            f(map.at(s).first);
        }
    }
};







#endif //MITKADEM2_EX2_H
