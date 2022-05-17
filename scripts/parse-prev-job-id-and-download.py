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
  TOKEN = "glpat-UAyNtbYBMZQxPv_h2jzs" #sys.argv[1]
  API = "https://git.chalmers.se/api/v4/projects/5345"
  url = f"{API}/jobs"
  response = requests.get(url, headers={ "PRIVATE-TOKEN": TOKEN })
  data = json.loads(response.text)
  id = data[1]["id"]
  # curl --output test.zip -H "PRIVATE-TOKEN: glpat-UAyNtbYBMZQxPv_h2jzs" https://git.chalmers.se/api/v4/projects/5345/jobs/197615/artifacts
  # "curl -location --output vresults.zip https://git.chalmers.se/api/v4/projects/$CI_PROJECT_ID/jobs/artifacts/main/download?job=build-and-test&job_token=$CI_JOB_TOKEN"
  subprocess.run(["curl", "-o", "vresults.zip", "--globoff", "-H", f"JOB-TOKEN: {sys.argv[1]}", f"{API}/jobs/{id}/artifacts"])
  subprocess.run(["ls", "-al"])
  subprocess.run(["cat", "vresults.zip"])
  with zipfile.ZipFile("./vresults.zip", "r") as zip_ref:
      zip_ref.extractall(".")
  subprocess.run(["mv", "vresults", "verification-results"])
