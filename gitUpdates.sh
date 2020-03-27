#!/bin/zsh
# This script automates repository updates
# Assume that you are already in master branch

function autoPush(){
  echo "Updating and pushing to master branch";
  git add .;
  
  if [[ $# -eq 0 ]]; then
    git commit -m "Modified and updated files";
  else
    git commit -m $1;
  fi

  git push;
  echo "Commit has been successfully pushed to master brnch";
}

autoPush $1
