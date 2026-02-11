#!/bin/bash

# Array of specific dates you want to fill
dates=(
  "2026-02-11"
  "2026-02-13"
  "2026-02-15"
  "2026-02-07"
  "2026-02-10"
)

for date in "${dates[@]}"; do
  DATE="${date}T12:00:00"
  echo "update on $date" >> log.txt
  git add .
  GIT_AUTHOR_DATE="$DATE" GIT_COMMITTER_DATE="$DATE" git commit -m "Update $date"
done

git push origin main