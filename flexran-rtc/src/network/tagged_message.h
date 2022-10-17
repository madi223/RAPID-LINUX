/*
 * Copyright 2016-2018 FlexRAN Authors, Eurecom and The University of Edinburgh
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License.  You may obtain a copy
 * of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 * For more information about Mosaic5G:  contact@mosaic-5g.io
 */

/*! \file    tagged_message.h
 *  \brief   represent a protobuf message with a tag
 *  \authors Xenofon Foukas
 *  \company Eurecom
 *  \email   x.foukas@sms.ed.ac.uk
 */

#ifndef TAGGED_MESSAGE_H_
#define TAGGED_MESSAGE_H_

#include <cstring>
#include <cstdlib>

namespace flexran {

  namespace network {

    class tagged_message {
      
      enum { max_normal_msg_size = 2048 };
      
    public:
      
      tagged_message(char *msg, std::size_t size, int tag);
      
      tagged_message(std::size_t size, int tag);
      
      tagged_message(const tagged_message& m);
      
      tagged_message(tagged_message&& other);

      tagged_message& operator=(tagged_message&& other);
      
      int getTag() const { return tag_; }
      
      int getSize() const { return size_; }
      
      char * getMessageArray() {return msg_contents_;}
  
      const char* getMessageContents() const { return msg_contents_; }
      
      ~tagged_message();
  
    private:
      
      std::size_t size_;
      int tag_;
      char p_msg_[max_normal_msg_size];
      char *msg_contents_;
      bool dynamic_alloc_;
    };

  }
  
}

#endif