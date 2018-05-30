/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   person.h
 * Author: oorra
 *
 * Created on February 13, 2018, 6:22 PM
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>

#include <odb/core.hxx>     // (1)

#pragma db object           // (2)
class person
{
public:
  person (const std::string& first,
          const std::string& last,
          unsigned short age);

  const std::string& first () const;
  const std::string& last () const;

  unsigned short age () const;
  void age (unsigned short);

private:
    
  person () {}              // (3)

  friend class odb::access; // (4)

  #pragma db id auto        // (5)
  unsigned long id_;        // (5)
  std::string first_;
  std::string last_;
  unsigned short age_;
};

#endif /* PERSON_H */

