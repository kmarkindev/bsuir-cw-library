#include "FileStorageService.h"

std::string FileStorageService::SaveFileToStorage(const std::string& fileData)
{
    std::filesystem::create_directories(_storagePath);

    auto fileGuid = drogon::utils::getUuid();

    std::ofstream of(std::filesystem::path(_storagePath) / fileGuid);
    of.write(fileData.c_str(), static_cast<std::streamsize>(fileData.size()));

    return fileGuid;
}

FileStorageService::FileStorageService(std::string_view storagePath)
    : _storagePath(storagePath)
{

}

void FileStorageService::ReplaceFileInStorage(const std::string& newFileData, std::string_view filePath)
{
    std::filesystem::create_directories(_storagePath);

    std::ofstream of(std::filesystem::path(_storagePath) / filePath, std::ios::trunc);
    of.write(newFileData.c_str(), static_cast<std::streamsize>(newFileData.size()));
}

void FileStorageService::RemoveFileFromStorage(std::string_view filePath)
{
    std::filesystem::remove(std::filesystem::path(_storagePath) / filePath);
}

std::string FileStorageService::GetFilePathFromStorage(std::string_view filePath)
{
    return (std::filesystem::path(_storagePath) / filePath).string();
}
