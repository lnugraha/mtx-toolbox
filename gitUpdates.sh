#!/bin/zsh

# $1="Updated existing modules and added new files";

fcn autoPush($1){
  echo "Updating and pushing to master repository";
  git add .;
  
  if [[ !$1 ]]; then
    git commit -m "Test";
  else
    git commit -m $1;
  fi
  git push;
}

autoPush$1
