#pragma once

#include <string>
#include <filesystem>
#include <fstream>
#include <drogon/utils/Utilities.h>

class FileStorageService
{
public:

    explicit FileStorageService(std::string_view storagePath);

    std::string SaveFileToStorage(const std::string& fileData);
    void ReplaceFileInStorage(const std::string& newFileData, std::string_view filePath);
    void RemoveFileFromStorage(std::string_view filePath);
    std::string GetFilePathFromStorage(std::string_view filePath);

private:

    std::string _storagePath;

};


