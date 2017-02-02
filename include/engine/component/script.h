#include <preprocessor.h>
#include "component.h"
#include <driver/scripting/luaHandler.h>
#pragma once

namespace reboot{
    class REBOOT_API Script: public Component{
        const char* m_Name;
        BYTE m_Type;
        //STATE IS LOCAL FOR EACH COMPONENT,
        //---ContextManager required to set up everything

        //Maybe map every type to a vector and call accordingly
        //---pros: easier to call, more processing (not much) time at update
        //---cons: more processing time at start and more memory
    public:
        Script(const char* name, BYTE type):
                Component(),m_Name(name),m_Type(type){

        }
        void bind(){

        }
        void unbind(){

        }
        void update() override{
            switch(m_Type){
                default:
                case SCRIPT_LUA:
                    break;
            }
        }

        void begin() override;

        void end() override;
    };
}