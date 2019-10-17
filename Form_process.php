<?php

require 'class.file.php';

$fileUpload = new File();
$fileUpload->setUploadPath($_SERVER['DOCUMENT_ROOT'].'/FileUpload/uploads/');
$fileUpload->whitelistFormats(array('image/png','image/jpeg','image/jpg','image/gif'));

$fileUpload->uploadFile($_FILES['file']);
