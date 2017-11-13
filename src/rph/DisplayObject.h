/*
 * DisplayObject.h
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

#pragma once

#include "cinder/App/App.h"
#include "cinder/CinderMath.h"
#include "cinder/Utilities.h"
#include "cinder/Timeline.h"
#include "rph/Object.h"

namespace rph {
    
    class DisplayObject3D : public Object{
    public:
        DisplayObject3D():mPos(ci::vec3(0)),mOffset(ci::vec3()),mScale(ci::vec3(1)),mColorA(ci::ColorA::white()),mRotation(ci::vec3(0)){};
        ~DisplayObject3D(){};
        
        virtual void    setup(){};
        virtual void    update( float deltaTime = 0.0f ){};
        virtual void    draw(){};
        
        void            setPos(ci::vec3 pos){ mPos = pos; }
        ci::vec3        getPos(){ return mPos; }
        
        void            setOffset(ci::vec3 offset){ mOffset = offset; }
        ci::vec3        getOffset(){ return mOffset; }
        
        void            setAlpha(float alpha){ mColorA.a = alpha; }
        float           getAlpha(){ return mColorA.a; }
        void            setColor(ci::Color color){ mColorA = ci::ColorA(color, mColorA.a ); }
        ci::Color       getColor(){ return ci::Color(mColorA); }
        void            setColorA(ci::ColorA color){ mColorA = color; }
        ci::ColorA      getColorA(){ return mColorA; }
        
        ci::vec3        getScale(){ return mScale; }
        float           getScaleY(){ return mScale.y; }
        float           getScaleX(){ return mScale.x; }
        float           getScaleZ(){ return mScale.z; }
        void            setScale(float scale){ mScale = ci::vec3(scale, scale, scale); }
        void            setScale(ci::vec3 scale){ mScale = scale; }
        void            setScaleY(float scaleY){ mScale.y = scaleY; }
        void            setScaleX(float scaleX){ mScale.x = scaleX; }
        void            setScaleZ(float scaleZ){ mScale.z = scaleZ; }
        
        void            setRotation(ci::vec3 rotation){ mRotation = rotation; }
        ci::vec3       getRotation(){ return mRotation; }
        
        std::string     name;
        
    protected:
        ci::vec3       mScale;
        ci::vec3       mPos;
        ci::vec3       mOffset;
        ci::vec3       mRotation;
        
    private:
        ci::ColorA      mColorA;
        
    };
    
    
    class DisplayObject2D : public Object{
      public:
        DisplayObject2D():mPos(ci::vec2(0)),mOffset(ci::vec2(0)),mScale(ci::vec2(1)),mColorA(ci::ColorA::white()),mWidth(0.0f),mHeight(0.0f),mRotation(0.0f),bDebug(false),mDebugColor(ci::ColorA(0,1,0,1)){};
        ~DisplayObject2D(){};
        
        enum RegistrationPoint{
            TOPLEFT,
            TOPCENTER,
            TOPRIGHT,
            CENTERLEFT,
            CENTERCENTER,
            CENTERRIGHT,
            BOTTOMLEFT,
            BOTTOMCENTER,
            BOTTOMRIGHT
        };
        
        virtual void setup(){};
        virtual void update( float deltaTime = 0.0f ){};
        virtual void draw(){};
        
        ci::vec2   getRegPointVec2(ci::Rectf rect, RegistrationPoint regPoint);
        ci::vec2   getRegPointVec2(ci::vec2 size, RegistrationPoint regPoint);
        ci::vec2   getRegPointVec2();
        void        setRegPoint(RegistrationPoint p){ mRegPoint = p; }
        RegistrationPoint getRegPoint(){ return mRegPoint; }
        static RegistrationPoint getRegPoint( std::string regPoint );
        
        
        void        setPos(float width, float height){ mPos = ci::vec2(width, height); }
        void        setPos(ci::vec2 pos){ mPos = pos; }
        ci::vec2   getPos(){ return mPos; }
        
        void        setOffset(ci::vec2 offset){ mOffset = offset; }
        ci::vec2   getOffset(){ return mOffset; }
        
        void        setHeight(float height){ mHeight = height; }
        float       getHeight(){ return mHeight; }
        
        void        setWidth(float width){ mWidth = width; }
        float       getWidth(){ return mWidth; }
        
        ci::vec2   getSize(){ return ci::vec2(mWidth, mHeight); }
        void        setSize(ci::vec2 size){ mWidth = size.x; mHeight = size.y; }
        void        setSize(float x, float y){ mWidth = x; mHeight = y; }
        
        ci::Rectf   getRect(){ return ci::Rectf(getUpperLeft(),getLowerRight());}
        ci::Area    getInteriorArea(){ return getRect().getInteriorArea(); }
        
        ci::vec2   getUpperLeft(){ return mPos; }
        ci::vec2   getLowerLeft(){ return mPos()+ci::vec2(0,mHeight) ; }
        ci::vec2   getUpperRight(){ return mPos()+ci::vec2(mWidth,0) ; }
        ci::vec2   getLowerRight(){ return mPos()+ci::vec2(mWidth,mHeight); }
        
        void        setAlpha(float alpha){ mColorA().a = alpha; }
        float       getAlpha(){ return mColorA().a; }
        void        setColor(ci::Color color){ mColorA = ci::ColorA(color, mColorA().a ); }
        ci::Color   getColor(){ return ci::Color( mColorA() ); }
        void        setColorA(ci::ColorA color){ mColorA = color; }
        ci::ColorA  getColorA(){ return mColorA; }
        
        void        setRotation(float rotation){ mRotation = rotation; }
        float       getRotation(){ return mRotation; }
        
        ci::vec2   getScale(){ return mScale; }
        float       getScaleY(){ return mScale().y; }
        float       getScaleX(){ return mScale().x; }
        void        setScale(float scale){ mScale = ci::vec2(scale, scale); }
        void        setScale(ci::vec2 scale){ mScale = scale; }
        void        setScaleY(float scaleY){ mScale().y = scaleY; }
        void        setScaleX(float scaleX){ mScale().x = scaleX; }
        
        std::string             name;
        
        bool                    bDebug;
        ci::ColorA              mDebugColor;
      
        ci::Anim<ci::vec2>      mPos;
        ci::Anim<ci::vec2>      mOffset;
        ci::Anim<float>         mHeight;
        ci::Anim<float>         mWidth;
        
        ci::Anim<float>         mRotation;
        ci::Anim<ci::vec2>      mScale;
        ci::Anim<ci::ColorA>    mColorA;
        RegistrationPoint       mRegPoint;
      protected:
      private:
        
    };
}
