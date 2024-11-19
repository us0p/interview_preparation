signal the intention to contribute in the issue tracker, either by filing a
new issue or by claiming an existing one.

the go project consists of:
- the main go repository, which contains the source code for the Go 
  language.
- golang.org/x/... repositories, contain various tools and infrastructure 
  that support Go. For example, golang.org/x/pkgsite is for pkg.go.dev, 
  golang.org/x/playground is for the Go playground, and golang.org/x/tools
  contains a variety of go tools, including the Go language server, gopls.
  you can see a list of all the golang.org/x/... repositories on 
  go.googlesource.com

The majority of the golang.org/x/... repos also use the main Go issue 
tracker. However a few of these repositories manage their issues 
separately. Be sure to check the right tracker for the repository to which
you would like to contribute.

some labels for issues:
- NeedsInvestigation: The issue is not fully understood and requires 
  analysis to understand the root cause.
- NeedsDecision: the issue is relatively well understood, but the Go team 
  hasn't yet decided the best way to address it. It would be better to wait
  for a decision before writing code. If you are interested in working on 
  an issue in this state, feel free to "ping" maintainers in the issue's 
  comments if some time has passed without a decision.
- NeedsFix: the issue is fully understood and code can be written to fix it.


You can use GitHub's search functionality to find issues to help out with.
Examples:
- Issues that need investigation:
  is:issue is:open label:NeedsInvestigation
- Issues that need a fix:
  is:issue is:open label:NeedsFix
- Issues that need a fix and have a suggested change:
  is:issue is:open label:NeedsFix ("golang.org/cl" OR "go.dev/cl")
- Issues that need a fix and do not have a suggested change:
  is:issue is:open label:NeedsFix NOT "golang.org/cl" NOT "go.dev/cl"

all contributions should be connected to an existing issue.

when planning work, please note that the Go project follows a six-month 
development cycle for the main Go repository.
The latter half of each cycle is a three-month feature freeze during which
only bug fixes and documentation updates are accepted.
New contributions can be sent during a feature freeze, but they will not be
merged until the freeze is over.
The freeze applies to the entire main repository as well as to the code in
golang.org/x/...that is needed to build the binaries included in the 
release.
The list of packages vendored into the standard library and the go command.

significant changes to the language, libraries, or tools must go through 
the change proposal process.

Even though Go maintainers use Gerrit for code review, a bot called 
Gopherbot has been created to sync GitHub pull requests to Gerrit.

When you open a pull request, Gopherbot will create a corresponding Gerrit
change list (CL) and post a link to it on your GitHub pull request; updates
to the pull request will also get reflected in the Gerrit CL. Whn somebody
comments on the CL, their comment will be also posted in your pull request,
so you will get a notification.
You need a Gerrit account to resond to your reviewers, including to mark 
feedback as 'Done' if implemented as suggested.

if you're making a change to the main go repository
git clone https://go.googlesource.com/go
cd go/src
./all.bash # compile and test

if you're making a change to one of the golang.org/x/... repositories
git clone https://go.googlesource.com/tools #.../tools in this example
cd tools
go test ./... # compile and test

prepare changes in a new branch, created from the master branch.
to commit the changes, use git-codereview change, it'll create or amend a 
single commit in the branch.
test your changes either by running the tests in the package you edited or
by re-running all.bash.
Send changes for review to Gerrit using git codereview mail (which doesn't
use e-mail, despite the name).
after a review, apply changes to the same single commit and mail them to 
Gerrit again.

[edit files...]
git add [files ...]
git codereview change # update same commit
git codereview mail # send to Gerrit again

git codereview change adds a unique Change-Id line near the bottom. That 
line is used by Gerrit to match
successive uploads of the same change. Do not edit or delete it.
If you need to edit the files again, you can stage the new changes and 
re-run git codereview change: each subsequent run will amend the existing 
commit while preserving the Change-Id.
Make sure that you always keep a single commit in each branch. If you add 
more commits by mistake, you can use git rebase to squash them together 
into a single one. 

You can use make.bash instead of all.bash to just build the compiler and 
the standard library without running the test suite.
Once the go tool is built, it will be installed as bin/go under the 
directory in which you cloned the Go repository, and you can run it 
directly from there.

always check the documentation for the repository in which you are working
in the README file in the root of the repository

Go maintainers will review your code on Gerrit, and you will get 
notifications via e-mail.

Commit messages in Go follow a specific set of conventions:
Here is a good example:
math: improve Sin, Cos and Tan precision for very large arguments

The existing implementation has poor numerical properties for
large arguments, so use the McGillicutty algorithm to improve
accuracy above 1e10.

The algorithm is described at https://wikipedia.org/wiki/McGillicutty_Algorithm

Fixes #159

First line: is conventionally a short-one-line summary of the change, 
prefixed by the primary affected package.
A rule of thumb is that is should be written so to complete te sentence 
"This change modifies Go to _____".
That means it doesn't start with a capital letter, is not a complete 
sentence, and actually summarizes the result of the change.

Follow the first line by a blank line.

Main content: The rest of the description elaborates and should provide 
context for the change and explain what it does. Write in complete 
sentences with correct punctuation. Don't use any other markup language.
Add any relevant information, such as benchmark data if the change affects
performance. The benchstat tool is conventionally used to format benchmark
data for change descriptions.

Referencing issues: The special notation "Fixes #12345" associates the 
change with issue 12345 in the Go issue tracker. When this change is 
eventually applied, the issue tracker will automatically mark the issue as
fixed. 
If the change is a partial step towards the resolution of the issue, write
"Updates #12345" instead.
If you are sending a change against a golang.org/x/... repository, you must
use the fully-qualified syntax supported by GitHub to make sure the change
is linked to the issue in the main repository, not the x/ repository. Most
issues are tracked in the main repository's issue tracker. The correct form
is "Fixes golang/go#159".


After an initial reading of your change, maintainers will trigger trybots,
a cluster of servers that will run the full test suite on several different
architectures.
If the trybot run fails, follow the link and check the full logs of the 
platforms on which the tests failed.


Think of each review comment like a ticket: you are expected to somehow 
"close" it by acting on it, either by implementing the suggestion or 
convincing the reviewer otherwise.


After you update the change, go through the review comments and make sure 
to reply to every one. You can click the "Done" button to reply indicating
that you've implemented the reviewer's suggestion; otherwise, click on 
"Reply" and explain why you have not, or what you have done instead.


As they near a decision, reviewers will apply a Code-Review “vote” to your
change. There are two possible votes:
- +2 The change is approved for being merged. Only Go maintainers (also 
  referred to as “approvers”) can cast a +2 vote.
- +1 The change looks good, but either the reviewer is requesting minor 
  changes before approving it, or they are not a maintainer and cannot 
  approve it, but would like to encourage an approval.
- Maintainers can also apply a Hold +1 vote to the change, to mark a change
  that should not be submitted now


When working on the main Go repository and using gopls with your editor, 
the go command invoked by gopls must correspond to the version of the 
source code you are working on.

 New files that you contribute should use the standard copyright header:

// Copyright 2024 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

Files in the repository are copyrighted the year they are added. Do not 
update the copyright year on files that you change. 

The go tool built by $GOROOT/src/make.bash will be installed in 
$GOROOT/bin/go and you can invoke it to test your code. For instance, if 
you have modified the compiler and you want to test how it affects the test
suite of your own project

If you're changing the standard library, you probably don't need to rebuild
the compiler: you can just run the tests for the package you've changed. 
You can do that either with the Go version you normally use, or with the Go
compiler built from your clone

If you're modifying the compiler itself, you can just recompile the compile
tool. After that, you will want to test it by compiling or running something.

The same applies to other internal tools of the Go tool chain, such as asm,
cover, link, and so on. Just recompile and install the tool using go 
install cmd/<TOOL> and then use the built Go binary to test it.

to update your local branch
git-codereview sync
