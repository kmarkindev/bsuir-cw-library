# bsuir-cw-library
[![Docker image build and push](https://github.com/kmarkindev/bsuir-cw-library/actions/workflows/build-and-push-docker-image.yml/badge.svg?branch=prod&event=push)](https://github.com/kmarkindev/bsuir-cw-library/actions/workflows/build-and-push-docker-image.yml)

A Library management system with an API written in C++/drogon and a Client written in C++/wxWidgets.
This is my coursework for my second term in [BSUIR](https://www.bsuir.by/en/).

Production runs on the following domain: [lib.kmarkin.com](http://lib.kmarkin.com/).
It will be alive at least until 10th of June 2022.

Docker image building and production deploy are automated via GitHub Actions.
If you need to start them, the only thing you need to do is to push new commits to the **prod** branch.

You can find all API requests 
[here in Postman public workspace](https://www.postman.com/kmarkindev/workspace/bsuir-cw-library).

Client GUI is generated using [wxFormBuilder v3.10.1](https://github.com/wxFormBuilder/wxFormBuilder).
You can find it's project file in *Sources/Client/Windows/WxBuilder* folder.

Tested compilers:
- MSVC
- GCC
- Mingw-w64 GCC POSIX

*Note: Make sure you've specified RC compiler when building client app on Windows since it uses .rc files.*
