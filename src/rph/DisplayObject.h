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

#include "cinder/App/AppNative.h"
#include "cinder/CinderMath.h"
#include "cinder/Utilities.h"
#include "cinder/Timeline.h"
#include "rph/Object.h"

namespace rph {
    
    class DisplayObject3D : public Object{
    public:
        DisplayObject3D():mPos(ci::Vec3f::zero()),mOffset(ci::Vec3f::zero()),mScale(ci::Vec3f::one()),mColorA(ci::ColorA::white()),mRotation(ci::Vec3f::zero()){};
        ~DisplayObject3D(){};
        
        virtual void    setup(){ };
        virtual void    update(  float deltaTime = 0.0f ){};
        virtual void    draw(){};
        
        void            setPos(ci::Vec3f pos){ mPos = pos; }
        ci::Vec3f       getPos(){ return mPos; }
        
        void            setOffset(ci::Vec3f offset){ mOffset = offset; }
        ci::Vec3f       getOffset(){ return mOffset; }
        
        void            setAlpha(float alpha){ mColorA.a = alpha; }
        float           getAlpha(){ return mColorA.a; }
        void            setColor(ci::Color color){ mColorA = ci::ColorA(color, mColorA.a ); }
        ci::Color       getColor(){ return ci::Color(mColorA); }
        void            setColorA(ci::ColorA color){ mColorA = color; }
        ci::ColorA      getColorA(){ return mColorA; }
        
        ci::Vec3f       getScale(){ return mScale; }
        float           getScaleY(){ return mScale.y; }
        float           getScaleX(){ return mScale.x; }
        float           getScaleZ(){ return mScale.z; }
        void            setScale(float scale){ mScale = ci::Vec3f(scale, scale, scale); }
        void            setScale(ci::Vec3f scale){ mScale = scale; }
        void            setScaleY(float scaleY){ mScale.y = scaleY; }
        void            setScaleX(float scaleX){ mScale.x = scaleX; }
        void            setScaleZ(float scaleZ){ mScale.z = scaleZ; }
        
        void            setRotation(ci::Vec3f rotation){ mRotation = rotation; }
        ci::Vec3f       getRotation(){ return mRotation; }
        
        std::string     name;
        
    protected:
        ci::Vec3f       mScale;
        ci::Vec3f       mPos;
        ci::Vec3f       mOffset;
        ci::Vec3f       mRotation;
        
    private:
        ci::ColorA      mColorA;
        
    };
    
    
    class DisplayObject2D : public Object{
      public:
        DisplayObject2D():mPos(ci::Vec2f::zero()),mOffset(ci::Vec2f::zero()),mScale(ci::Vec2f::one()),mColorA(ci::ColorA::white()),mWidth(0.0f),mHeight(0.0f),mRotation(0.0f),bDebug(false),mDebugColor(ci::ColorA(0,1,0,1)){};
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
        
        ci::Vec2f   getRegPointVec2f(ci::Rectf rect, RegistrationPoint regPoint);
        ci::Vec2f   getRegPointVec2f();
        void        setRegPoint(RegistrationPoint p){ mRegPoint = p; }
        RegistrationPoint getRegPoint(){ return mRegPoint; }
        static RegistrationPoint getRegPoint( std::string regPoint );
        
        
        void        setPos(float width, float height){ mPos = ci::Vec2f(width, height); }
        void        setPos(ci::Vec2f pos){ mPos = pos; }
        ci::Vec2f   getPos(){ return mPos; }
        
        void        setOffset(ci::Vec2f offset){ mOffset = offset; }
        ci::Vec2f   getOffset(){ return mOffset; }
        
        void        setHeight(float height){ mHeight = height; }
        float       getHeight(){ return mHeight; }
        
        void        setWidth(float width){ mWidth = width; }
        float       getWidth(){ return mWidth; }
        
        ci::Vec2f   getSize(){ return ci::Vec2f(mWidth, mHeight); }
        void        setSize(ci::Vec2f size){ mWidth = size.x; mHeight = size.y; }
        void        setSize(float x, float y){ mWidth = x; mHeight = y; }
        
        ci::Rectf   getRect(){ return ci::Rectf(getUpperLeft(),getLowerRight());}
        ci::Area    getInteriorArea(){ return getRect().getInteriorArea(); }
        
        ci::Vec2f   getUpperLeft(){ return mPos; }
        ci::Vec2f   getLowerLeft(){ return mPos()+ci::Vec2f(0,mHeight) ; }
        ci::Vec2f   getUpperRight(){ return mPos()+ci::Vec2f(mWidth,0) ; }
        ci::Vec2f   getLowerRight(){ return mPos()+ci::Vec2f(mWidth,mHeight); }
        
        void        setAlpha(float alpha){ mColorA().a = alpha; }
        float       getAlpha(){ return mColorA().a; }
        void        setColor(ci::Color color){ mColorA = ci::ColorA(color, mColorA().a ); }
        ci::Color   getColor(){ return ci::Color( mColorA() ); }
        void        setColorA(ci::ColorA color){ mColorA = color; }
        ci::ColorA  getColorA(){ return mColorA; }
        
        void        setRotation(float rotation){ mRotation = rotation; }
        float       getRotation(){ return mRotation; }
        
        ci::Vec2f   getScale(){ return mScale; }
        float       getScaleY(){ return mScale().y; }
        float       getScaleX(){ return mScale().x; }
        void        setScale(float scale){ mScale = ci::Vec2f(scale, scale); }
        void        setScale(ci::Vec2f scale){ mScale = scale; }
        void        setScaleY(float scaleY){ mScale().y = scaleY; }
        void        setScaleX(float scaleX){ mScale().x = scaleX; }
        
        std::string name;
        
        bool        bDebug;
        ci::ColorA  mDebugColor;
      
        ci::Anim<ci::Vec2f>   mPos;
        ci::Anim<ci::Vec2f>   mOffset;
        ci::Anim<float>       mHeight;
        ci::Anim<float>       mWidth;
        
        ci::Anim<float>       mRotation;
        ci::Anim<ci::Vec2f>   mScale;
        ci::Anim<ci::ColorA>  mColorA;
        RegistrationPoint     mRegPoint;
      protected:
      private:
        
    };
}
