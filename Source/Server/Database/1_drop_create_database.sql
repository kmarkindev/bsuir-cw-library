DROP DATABASE IF EXISTS bsuir_library;
CREATE DATABASE bsuir_library;

USE bsuir_library;

CREATE TABLE authors (
    id BIGINT UNSIGNED PRIMARY KEY AUTO_INCREMENT NOT NULL,
    name VARCHAR(32) NOT NULL
);

CREATE TABLE publishers (
    id BIGINT UNSIGNED PRIMARY KEY AUTO_INCREMENT NOT NULL,
    name VARCHAR(32) NOT NULL
);

CREATE TABLE books (
    id BIGINT UNSIGNED PRIMARY KEY AUTO_INCREMENT NOT NULL,
    name VARCHAR(64) NOT NULL,
    author_id BIGINT UNSIGNED NOT NULL,
    publisher_id BIGINT UNSIGNED NOT NULL,
    published_at DATE NOT NULL,
    file_storage_path VARCHAR(255) NULL,
    file_extension VARCHAR(16) NULL,

    CONSTRAINT books_author_id_to_authors_id
    FOREIGN KEY (author_id) REFERENCES authors (id),

    CONSTRAINT books_publisher_id_to_publishers_id
    FOREIGN KEY (publisher_id) REFERENCES publishers (id)
);

CREATE TABLE book_instances (
    id BIGINT UNSIGNED PRIMARY KEY AUTO_INCREMENT NOT NULL,
    book_id BIGINT UNSIGNED NOT NULL,

    CONSTRAINT book_instances_book_id_to_books_id
    FOREIGN KEY (book_id) REFERENCES books (id)
);

CREATE TABLE readers (
    id BIGINT UNSIGNED PRIMARY KEY AUTO_INCREMENT NOT NULL,
    name VARCHAR(64) NOT NULL,
    address VARCHAR(64) NOT NULL,
    birthday DATE NOT NULL,
    sex BOOL NOT NULL,
    phone VARCHAR(32) NULL,
    email VARCHAR(32) NULL
);

CREATE TABLE book_withdraws (
    id BIGINT UNSIGNED PRIMARY KEY AUTO_INCREMENT NOT NULL,
    book_instance_id BIGINT UNSIGNED UNIQUE NOT NULL,
    reader_id BIGINT UNSIGNED NOT NULL,
    withdrawn_at DATE NOT NULL,
    return_at DATE NOT NULL,

    CONSTRAINT book_withdraws_book_instance_id_to_book_instances_id
    FOREIGN KEY (book_instance_id) REFERENCES book_instances (id)
    ON DELETE CASCADE,

    CONSTRAINT book_withdraws_reader_id_to_readers_id
    FOREIGN KEY (reader_id) REFERENCES readers (id)
);