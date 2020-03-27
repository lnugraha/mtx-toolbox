#!/bin/zsh

# $1="Updated existing modules and added new files";

fcn autoPush($1){
  echo "Updating and pushing to master repository";
  git add .;
  git commit -m $1;
  git push;
}

autoPush$1
