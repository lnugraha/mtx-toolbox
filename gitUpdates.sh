#!/bin/zsh
function autoPush(){
  echo "Updating and pushing to master repository";
  git add .;
  if [[ $# -eq 0 ]]; then
    git commit -m "Modified and updated files";
  else
    git commit -m $1;
  fi
  git push;
  echo "Pushing success";
}

autoPush $1
