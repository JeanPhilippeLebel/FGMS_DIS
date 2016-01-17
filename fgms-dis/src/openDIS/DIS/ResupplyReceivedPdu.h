#ifndef RESUPPLYRECEIVEDPDU_H
#define RESUPPLYRECEIVEDPDU_H

#include <DIS/EntityID.h>
#include <DIS/EntityID.h>
#include <DIS/SupplyQuantity.h>
#include <vector>
#include <DIS/LogisticsFamilyPdu.h>
#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// Section 5.3.5.3. Receipt of supplies is communiated. COMPLETE

// Copyright (c) 2007-2012, MOVES Institute, Naval Postgraduate School. All rights reserved. 
// Licensed under the BSD open source license. See http://www.movesinstitute.org/licenses/bsd.html
//
// @author DMcG, jkg

#pragma warning(disable: 4251 ) // Disables warning for stl vector template DLL export in msvc

class EXPORT_MACRO ResupplyReceivedPdu : public LogisticsFamilyPdu
{
protected:
  /** Entity that is receiving service */
  EntityID _receivingEntityID; 

  /** Entity that is supplying */
  EntityID _supplyingEntityID; 

  /** how many supplies are being offered */
  unsigned char _numberOfSupplyTypes; 

  /** padding */
  short _padding1; 

  /** padding */
  char _padding2; 

  std::vector<SupplyQuantity> _supplies; 


 public:
    ResupplyReceivedPdu();
    virtual ~ResupplyReceivedPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityID& getReceivingEntityID(); 
    const EntityID&  getReceivingEntityID() const; 
    void setReceivingEntityID(const EntityID    &pX);

    EntityID& getSupplyingEntityID(); 
    const EntityID&  getSupplyingEntityID() const; 
    void setSupplyingEntityID(const EntityID    &pX);

    unsigned char getNumberOfSupplyTypes() const; 

    short getPadding1() const; 
    void setPadding1(short pX); 

    char getPadding2() const; 
    void setPadding2(char pX); 

    std::vector<SupplyQuantity>& getSupplies(); 
    const std::vector<SupplyQuantity>& getSupplies() const; 
    void setSupplies(const std::vector<SupplyQuantity>&    pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const ResupplyReceivedPdu& rhs) const;
};
}

#endif
// Copyright (c) 1995-2009 held by the author(s).  All rights reserved.
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
//  are met:
// 
//  * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
// * Neither the names of the Naval Postgraduate School (NPS)
//  Modeling Virtual Environments and Simulation (MOVES) Institute
// (http://www.nps.edu and http://www.MovesInstitute.org)
// nor the names of its contributors may be used to endorse or
//  promote products derived from this software without specific
// prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// AS IS AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
// ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.