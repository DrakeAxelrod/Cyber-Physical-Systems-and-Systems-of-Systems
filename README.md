# 2022-group-05



## Getting started

To clone the project ensure you have an active SSH key on your pc. You can confirm this by opening a terminal using the command 
``` 
cat ~/.ssh/id_ed25519.pub                                     
```

If you have an active SSH key that is registered on gitlab, skip to step 6.  
If you don't currently have an SSH key, follow these steps:

### Step 1

```
ssh-keygen -t ed25519 -C "<comment>"                      
```

### Step 2

```
Enter file in which to save the key (/home/<yourcomputer>/.ssh/id_ed25519): 
```
Choose a file or hit enter to accept the standard file location (the latter is recommended)

### Step 3

```
Enter passphrase (empty for no passphrase): 
```
Enter a password for the SSH key and press enter. This step is repeated to confirm the password.

### Step 4
Copy your SSH key to your clipboard.

### Mac
```
pbcopy < ~/.ssh/id_rsa.pub
```
### Linux (Ubuntu)
```
cat ~/.ssh/id_rsa.pub
```
(copy the output)
### Windows (Git Bash)
```
clip < ~/.ssh/id_rsa.pub
```

### Step 5
Add your SSH key to your gitlab environment.

Click on your avatar and Navigate to 'Preferences'.  
You will see the following screen:

![alt text](https://imgs.search.brave.com/jlUvYfoLOeAh8eXaAKnWDm4FFIJ0lvnNsHs28l5C0sc/rs:fit:1200:944:1/g:ce/aHR0cHM6Ly91cGxv/YWQtaW1hZ2VzLmpp/YW5zaHUuaW8vdXBs/b2FkX2ltYWdlcy82/MjY2NzM0LWVlM2E1/Y2QwNGY5MWI1ODUu/cG5n)

Add your SSH key that was copied in the previous step. Add a title and an expiry date.

### Step 6 

Clone the repository to your pc. First, copy the SSH repository url as displayed here:

![alt text](https://imgur.com/Fq2jXaQ.png)

Open a terminal and navigate to the folder where you want to copy the project using the 'cd' command. I.e:
``` 
cd Desktop/cloned-projects
```

Now, clone the project into the current folder using this command:

```
git clone git@git.chalmers.se:courses/dit638/students/2022...
```

### Now you're set to go!

## Feature management

### New features
The process that our team will follow incorporates these steps:

### Step 1
Team discussion and approval of feature.

### Step 2
Feature is added to requirements and user stories/tasks are created

### Step 3
User stories/task are added to the product backlog on Trello. 

### Step 4
During sprint planning, team members pull tasks from the product backlog to the sprint backlog and assign themselves. During the sprint, the feature will move through phases of 'Ongoing', 'To be reviewed', 'Done'.

### Step 5
An appropriate matching issue will be created by the assignee on gitlab referencing the milestone the feature belongs to.

### Step 6
The assignee branches from main, using a branch name that specifies the feature. Commits will be done at minimum on a daily basis where the issue will be added to the commit message.

### Step 7
When the task is complete, the assignee will create a merge request with detail concerning the work they have completed and how it solves the issue. They will also select a reviewer during this process. 

### Step 8 
Review will be completed, and if the code is satisfactory the merge will be finalised with the main branch.

### Step 9
During the sprint review, the feature will be demonstrated and will be approved/delayed by the team.

## Unexpected behaviour

### Step 1
The team identifies existing unexpected behaviour in the project and discusses the priority of the issue.

### Step 2
If the unexpected behaviour is affecting the functionality of the project, the task is added to the sprint backlog and assigned to a team member that has time to complete the task within the current or at maximum the next sprint.
If the flaw is not affecting the functionality of the project, the task is added to the product backlog and is handled as per the normal feature steps.

### Step 3
The team will be updated daily concerning the feature related to the unexpected behaviour and assistance will be provided to the assignee on an ongoing basis.

### Step 4
When the task is complete, the assignee will create a merge request with detail concerning the work they have completed and how it solves the issue. They will also select a reviewer during this process. 

### Step 5 
Review will be completed, and if the code is satisfactory the merge will be finalised with the main branch.

### Step 6
During the sprint review, the feature will be demonstrated and will be approved/delayed by the team.

## Commit messages
The commit messages shall include a short description of the intention of the completed code as well as the issue number related to the commit.

Example of non-accepted structure
```
"this is a commit"
```

Example of accepted structure
```
"added front IR sensor reading #2"
```

## Docker

In order to run the project, you need to have docker installed on your computer. There are various ways to install docker. Follow the instructions for your specific setup at [installation](https://docs.docker.com/get-docker/).

Once you've downloaded docker, navigate to the project repository in your terminal.

Run:
```
docker start
```

After docker has started successfully, and you're in the correct folder, run:
```
docker build -rm 2022-group-05/project -f Dockerfile .
```
This might take a while when you run it the first time. Once completed, you should be able to see the image with the following command:

```
docker images
```
The output will look like this:
![images](https://imgur.com/AJAvKw0l.png)

When the image has been built, run the image by using the following command:
```
docker run --rm 2022-group-05/project:latest <arguments>
```

This command will run the program and you will see the output based on the argument input.

### For further information, the contributors can be contacted:
Drake Axelrod - drake@draxel.io  
Klara Svensson - gussvekla@student.gu.se  
Sicily Brannen - gusbrannsi@student.gu.se  
Vernita Gouws - gusgouve@student.gu.se 
