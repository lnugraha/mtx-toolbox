#!/bin/zsh

function autoPush(){
  echo "Updating and pushing to master repository";
  git add .;
  
  if [[ $# -eq 0 ]]; then
    git commit -m "Modified and updated files";
    git push;
  else
    git commit -m $1;
    git push;
  fi
  echo "Pushing success";
}

autoPush $1
