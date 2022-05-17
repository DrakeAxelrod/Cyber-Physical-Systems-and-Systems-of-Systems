# make a http request
# parse the response
# print the job id
import requests
import json
import subprocess
import zipfile
import os
import time
import sys

if __name__ == "__main__":
  TOKEN = sys.argv[1]
  API = "https://git.chalmers.se/api/v4/projects/5345"
  url = f"{API}/jobs"
  response = requests.get(url, headers={ "JOB-TOKEN": TOKEN })
  data = json.loads(response.text)
  print(data)
  id = data[1]["id"]
  subprocess.run(["curl", "-o", "vresults.zip", "--globoff", "-H", f"JOB-TOKEN: {TOKEN}", f"{API}/jobs/{id}/artifacts"])
  subprocess.run(["ls", "-al"])
  with zipfile.ZipFile("./vresults.zip", "r") as zip_ref:
      zip_ref.extractall(".")
  subprocess.run(["mv", "vresults", "verification-results"])
