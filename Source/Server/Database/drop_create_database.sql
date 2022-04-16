DROP DATABASE IF EXISTS bsuir_library;
CREATE DATABASE bsuir_library;

USE bsuir_library;

CREATE TABLE authors (
    id BIGINT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(32)
);

CREATE TABLE publishers (
    id BIGINT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(32)
);

CREATE TABLE books (
    id BIGINT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(64),
    author_id BIGINT UNSIGNED,
    publisher_id BIGINT UNSIGNED,
    published_at DATE,
    file_storage_path VARCHAR(255) NULL,

    CONSTRAINT books_author_id_to_authors_id
    FOREIGN KEY (author_id) REFERENCES authors (id),

    CONSTRAINT books_publisher_id_to_publishers_id
    FOREIGN KEY (publisher_id) REFERENCES publishers (id)
);

CREATE TABLE book_instances (
    id BIGINT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
    book_id BIGINT UNSIGNED,

    CONSTRAINT book_instances_book_id_to_books_id
    FOREIGN KEY (book_id) REFERENCES books (id)
);

CREATE TABLE book_history (
    id BIGINT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
    book_instance_id BIGINT UNSIGNED,
    message TEXT(1024),

    CONSTRAINT book_history_book_instance_id_to_book_instances_id
    FOREIGN KEY (book_instance_id) REFERENCES book_instances (id)
    ON DELETE CASCADE
);

CREATE TABLE readers (
    id BIGINT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(64),
    address VARCHAR(64),
    birthday DATE,
    sex BOOL,
    phone VARCHAR(32) NULL,
    email VARCHAR(32) NULL
);

CREATE TABLE book_withdraws (
    id BIGINT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
    book_instance_id BIGINT UNSIGNED UNIQUE,
    reader_id BIGINT UNSIGNED,
    withdrawn_at DATE,
    return_at DATE,

    CONSTRAINT book_withdraws_return_at_more_than_withdrawn_at
    CHECK (book_withdraws.withdrawn_at < book_withdraws.return_at),

    CONSTRAINT book_withdraws_book_instance_id_to_book_instances_id
    FOREIGN KEY (book_instance_id) REFERENCES book_instances (id)
    ON DELETE CASCADE,

    CONSTRAINT book_withdraws_reader_id_to_readers_id
    FOREIGN KEY (reader_id) REFERENCES readers (id)
);