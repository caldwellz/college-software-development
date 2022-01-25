#include "wholeNumber.h"
#include <iomanip>
#include <sstream>

namespace custom
{

typedef list<int>::iterator listIterator;
typedef list<int>::reverse_iterator rlistIterator;
typedef list<int>::const_iterator clistIterator;

long abs(long input)
{
  return input < 0 ? -input : input;
}

void WholeNumber::fix(){
  short sign;

  while(values.back() == 0 && values.size() > 1)
    values.pop_back();

  if(*values.rbegin() < 0)
    sign = -1;
  else if(*values.rbegin() > 0)
    sign = 1;
  
  for(listIterator i = values.begin();
        i != values.rbegin();i++)
  {
    if(*i * sign < 0){
      if(*i < 0){
        *(i + 1) += -1;
        *i += VAR_MAX;
      }else{
        *(i + 1) +=1;
        *i += -VAR_MAX;
      }
    }
  }
  while(values.back() == 0 && values.size() > 1)
    values.pop_back();
}

void WholeNumber::add(int amount, listIterator i){
  if(i == values.end())
  {
    values.push_back(0);
    i = values.rbegin();
  }
  long temp = amount + *i;

  while(abs(temp) >= VAR_MAX){
    *i = temp % VAR_MAX;
    amount = (long)temp/VAR_MAX;
    i++;

    if(i == values.end())
    {
      values.push_back(0);
      i = values.rbegin();
    }
    temp = amount + *i;
  }
  *i = temp;
}

void WholeNumber::add(WholeNumber amount, int i){
  while(amount.values.size() + i > values.size())
    values.push_back(0);
  
  listIterator j2 = values.begin() + i;
  for(listIterator j = amount.values.begin();j != amount.values.end();j++,j2++){
    add(*j,j2);
  }
}

void WholeNumber::multiply(WholeNumber amount){
  WholeNumber out;
  WholeNumber temp;
  int i = 0;
  for (listIterator it = amount.values.begin();
        it != amount.values.end();it++,i++){
    temp = 0;
    int j = 0;
    for (listIterator jt = values.begin();jt != values.end();jt++,j++){
      temp.add(WholeNumber(long(*it) * long(*jt)),j);
    }
    out.add(temp,i);
  }
  *this = out;
}

std::ostream & operator << (std::ostream & out, WholeNumber t){
  std::stringstream ss;
  ss.fill('0');
  char hold[4];
  bool first = true;
  for (rlistIterator i = t.values.rbegin();i != t.values.rend();i++)
  {
    if(i != t.values.rbegin())
    {
      ss << std::setw(9) << abs(*i);
    }
    else
      ss << *i;

    while(ss.get(hold,4))
    {
      if(!first)
        out << ',';
      out << hold;
      first = false;
    }
    ss.clear();
  }
  
  return out;
}

WholeNumber operator ++(WholeNumber input)
{
  WholeNumber output(input);
  input += 1;
  return output;
}

bool operator == (WholeNumber a, WholeNumber b){
  if(a.values.size() == b.values.size()){
    rlistIterator ai = a.values.rbegin();
    rlistIterator bi = b.values.rbegin();
    for(;ai != a.values.rend() && bi != b.values.rend();ai++,bi++)
      if(*ai != *bi)
        return false;
    return true;
  }else 
    return false;
}

bool operator < (WholeNumber a, WholeNumber b){
  if (a.values.size() < b.values.size()) return true;
  if (a.values.size() == b.values.size()){
    rlistIterator ai = a.values.rbegin();
    rlistIterator bi = b.values.rbegin();
    for(;ai != a.values.rend() && bi != b.values.rend();ai++,bi++)
      if(*ai < *bi)
        return true;
  }
  return false;
}

bool operator <= (WholeNumber a, WholeNumber b){
  if (a.values.size() < b.values.size()) return true;
  if (a.values.size() == b.values.size()){
    rlistIterator ai = a.values.rbegin();
    rlistIterator bi = b.values.rbegin();
    for(;ai != a.values.rend() && bi != b.values.rend();ai++,bi++){
      if(*ai < *bi)
        return true;
      else if(*ai > *bi)
        return false;
    }
    return true;
  }
  return false;
}

bool operator >= (WholeNumber a, WholeNumber b){
  if (a.values.size() < b.values.size()) return true;
  if (a.values.size() == b.values.size()){
    rlistIterator ai = a.values.rbegin();
    rlistIterator bi = b.values.rbegin();
    for(;ai != a.values.rend() && bi != b.values.rend();ai++,bi++){
      if(*ai > *bi)
        return true;
      else if(*ai < *bi)
        return false;
    }
    return true;
  }
  return false;
}

void WholeNumber::operator= (WholeNumber input){
    values.clear();
    for(listIterator i = input.values.begin();i != input.values.end();i++)
      values.push_back(*i);
    fix();
}

WholeNumber::WholeNumber(long value) { 
  while(abs(value) >= VAR_MAX)
  {
    values.push_back(value % VAR_MAX);
    value /= VAR_MAX;
  }
  values.push_back(value);
}

WholeNumber::WholeNumber(const WholeNumber & value) { 
  for(clistIterator i = value.values.cbegin();i != value.values.cend();i++)
    values.push_back(*i);
}

WholeNumber::WholeNumber(std::string str){
  values.push_back(0);
  int len = str.length();
  int mul = 1;
  int o = 0;
  for(int i = 0;i < len;i++)
  {
    if (!((i-o) % 9)) mul = 1;
    int val = str[len - i - 1] - '0';
    if (val >= 0 && val <= 9){
      add(val * mul,(i-o)/9);
      mul *= 10;
    }else
      o++;
  }
}
};
