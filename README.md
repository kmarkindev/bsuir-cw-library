# bsuir-cw-library
[![Docker image build and push](https://github.com/kmarkindev/bsuir-cw-library/actions/workflows/build-and-push-docker-image.yml/badge.svg?branch=prod&event=push)](https://github.com/kmarkindev/bsuir-cw-library/actions/workflows/build-and-push-docker-image.yml)

A Library management system with an API written in C++/drogon and a Client written in C++/wxWidgets.
This is my coursework for the second term in [BSUIR](https://www.bsuir.by/en/).

Production runs on the following domain: [lib.kmarkin.com](http://lib.kmarkin.com/).
It will be alive at least utill 10th of June 2022.

Docker image building and production deploy are automated via GitHub Actions.
If you need to start them, the only thing you need to do is to push new commits to **prod** branch.

You can find all API requests 
[here in Postman public workspace](https://www.postman.com/kmarkindev/workspace/bsuir-cw-library)

*Note: one of the main requirement in this coursework is not to use SQL for data filtering, searching etc. 
So, please don't be confused when you see lots of places which can be replaced by a couple of SQL lines.*
