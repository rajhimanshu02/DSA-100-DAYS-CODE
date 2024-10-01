#!/bin/bash

# Array of specific dates you want to fill
dates=(
  "2024-10-01"
  "2024-10-05"
  "2024-10-12"
  "2024-11-03"
  "2024-11-20"
)

for date in "${dates[@]}"; do
  DATE="${date}T12:00:00"
  echo "update on $date" >> log.txt
  git add .
  GIT_AUTHOR_DATE="$DATE" GIT_COMMITTER_DATE="$DATE" git commit -m "Update $date"
done

git push origin main