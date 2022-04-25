#!/usr/bin/env bash

curl https://cdn.jsdelivr.net/gh/tommarshall/git-good-commit@v0.6.1/hook.sh > \
  .git/hooks/commit-msg && chmod +x .git/hooks/commit-msg
