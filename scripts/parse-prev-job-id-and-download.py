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

TOKEN = os.environ["ACCESS_TOKEN"]


if __name__ == "__main__":
  TOKEN = os.environ["ACCESS_TOKEN"]
  API = "https://git.chalmers.se/api/v4/projects/5345"
  url = f"{API}/jobs"
  response = requests.get(url, headers={ "PRIVATE-TOKEN": TOKEN })
  data = json.loads(response.text)
  id = data[1]["id"]
  subprocess.run(["curl", "-o", "vresults.zip", "--globoff", "-H", f"PRIVATE-TOKEN: {TOKEN}", f"{API}/jobs/{id}/artifacts"])
  subprocess.run(["ls", "-al"])
  with zipfile.ZipFile("vresults.zip", "r") as zip_ref:
      zip_ref.extractall(".")
  subprocess.run(["rm", "vresults.zip"])
  subprocess.run(["mv", "vresults", "verification-results"])
