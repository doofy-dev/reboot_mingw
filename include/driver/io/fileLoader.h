#pragma once

#include <cstdio>
#include <cstring>
#include <iostream>
#include "../../preprocessor.h"

#include <iostream>
#include <fstream>

namespace reboot_driver
{
	class REBOOT_API FileLoader
	{
    public:
        static const char* readAll(const char* filename){
            if (FILE* file = fopen(filename, "r")){
                fseek(file, 0, SEEK_END);
                unsigned long length = ftell(file);
                char* data = new char[length + 1];
                memset(data, 0, length + 1);
                fseek(file, 0, SEEK_SET);
                fread(data, 1, length, file);
                fclose(file);
                return data;
            }
            std::cout<<"File: "<<filename<<" does not exists"<<std::endl;
            return "";
        }
	};
}