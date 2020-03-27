#!/bin/zsh

# $1="Updated existing modules and added new files";

function autoPush(){
  echo "Updating and pushing to master repository";
  git add .;
  
  if [[ !$1 ]]; then
    git commit -m "Test";
    git push;
  else
    git commit -m $1;
    git push;
  fi
  echo "Pushing success";
}

autoPush $1
