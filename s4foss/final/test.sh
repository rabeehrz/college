#! /bin/bash

testfunc() {
  if [ $1 -eq 1 ]
  then
    return 1
  return 0
  fi
}

b=1
a=testfunc b
echo a