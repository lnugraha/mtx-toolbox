#!/bin/zsh

# $1="Updated existing modules and added new files";

fcn autoPush($1){
  echo "Updating and pushing to master repository";
  git add .;
  
  if [[ !$1 ]]; then
    git commit -m "Test";
    git push;
  else
    git commit -m $1;
    git push;
  fi
}

autoPush$1
