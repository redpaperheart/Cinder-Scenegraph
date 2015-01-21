/*
 * DisplayObject.cpp
 *
 * Created by Daniel Scheibel on 10/25/12.
 *
 * Copyright (c) 2012, Red Paper Heart, All rights reserved.
 * This code is intended for use with the Cinder C++ library: http://libcinder.org
 *
 * To contact Red Paper Heart, email hello@redpaperheart.com or tweet @redpaperhearts
 *
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in
 * the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "rph/DisplayObject.h"

namespace rph{
    ci::vec2 DisplayObject2D::DisplayObject2D::getRegPointVec2f(){
        return getRegPointVec2f( getRect(), getRegPoint() );
    }
    
    ci::vec2 DisplayObject2D::getRegPointVec2f(ci::Rectf rect, RegistrationPoint regPoint){
        switch(regPoint){
            case TOPLEFT:
                return ci::vec2(0);
            case TOPCENTER:
                return ci::vec2(-rect.getWidth()/2, 0);
            case TOPRIGHT:
                return ci::vec2(-rect.getWidth(), 0);
            case CENTERLEFT:
                return ci::vec2(0, -rect.getHeight()/2);
            case CENTERCENTER:
                return ci::vec2(-rect.getWidth()/2, -rect.getHeight()/2);
            case CENTERRIGHT:
                return ci::vec2(-rect.getWidth(), -rect.getHeight()/2);
            case BOTTOMLEFT:
                return ci::vec2(0, rect.getHeight());
            case BOTTOMCENTER:
                return ci::vec2(-rect.getWidth()/2, -rect.getHeight());
            case BOTTOMRIGHT:
                return ci::vec2(-rect.getWidth(), -rect.getHeight());
        }
        return ci::vec2(0);
    }
    
    DisplayObject2D::RegistrationPoint DisplayObject2D::getRegPoint( std::string regPoint ){
        if( regPoint == "TOPLEFT"){
            return TOPLEFT;
        }else if( regPoint == "TOPCENTER"){
            return TOPCENTER;
        }else if( regPoint == "TOPRIGHT"){
            return TOPRIGHT;
        }else if( regPoint == "CENTERLEFT"){
            return CENTERLEFT;
        }else if( regPoint == "CENTERCENTER"){
            return CENTERCENTER;
        }else if( regPoint == "CENTERRIGHT"){
            return CENTERRIGHT;
        }else if( regPoint == "BOTTOMLEFT"){
            return BOTTOMLEFT;
        }else if( regPoint == "BOTTOMCENTER"){
            return BOTTOMCENTER;
        }else if( regPoint == "BOTTOMRIGHT"){
            return BOTTOMRIGHT;
        }else{
            return TOPLEFT;
        }
    }
}