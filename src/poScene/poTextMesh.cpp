/*
 Copyright (c) 2015, Potion Design LLC
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 
 * Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 
 * Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.
 
 * Neither the name of copyright holder nor the names of its
 contributors may be used to endorse or promote products derived from
 this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "poTextMesh.h"
using namespace cinder;

namespace po { namespace scene {
  
  TextMeshRef TextMesh::create()
  {
    return TextMeshRef(new TextMesh(gl::SdfTextMesh::create(),Rectf()));
  }
  
  TextMeshRef TextMesh::create(gl::SdfTextMeshRef sdfTextMesh, ci::Rectf pBounds)
  {
    return TextMeshRef(new TextMesh(sdfTextMesh,pBounds));
  }
  
  TextMeshRef TextMesh::create(gl::SdfTextMeshRef sdfTextMesh, ci::gl::Texture::Format format, ci::Rectf pBounds)
  {
    TextMeshRef ref(new TextMesh(sdfTextMesh,pBounds));
    ref->setFormat(format);
    return ref;
  }
  
  TextMesh::TextMesh(gl::SdfTextMeshRef sdfTextMesh, ci::Rectf pBounds)
  : mSdfTextMesh(sdfTextMesh)
  , mUseTextBounds(false)
  , mHasFormat(false)
  {
    render();
    mBounds = pBounds;
  }
  
  void TextMesh::draw()
  {
    ci::gl::enableAlphaBlending();
    ci::gl::color(ci::ColorA(getFillColor(), getAppliedAlpha()));
    mSdfTextMesh->draw(false);
  }
  
  void TextMesh::setTextMesh(gl::SdfTextMeshRef &sdfTextMesh)
  {
    mSdfTextMesh = sdfTextMesh;
    render();
    
    // mUseTextBounds = mSdfTextMesh.getSize().y == gl::SdfTextMeshRef::GROW ? true : false;
  }
  
  void TextMesh::render()
  {
    
  }
  
  ci::Rectf TextMesh::getBounds()
  {
    if(mTexture)
    {
      return mTexture->getBounds();
    } else {
      return mBounds;
    }
  }
  
  void TextMesh::setFormat(ci::gl::Texture::Format format)
  {
    mFormat = format;
    mHasFormat = true;
    render();
  }
  
} } //  namespace po::scene
