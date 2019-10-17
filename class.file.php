<?php

class File{
  private $_supportedFormats=array();
  private $path;

  public function setUploadPath($path){
    $this->path=$path;
  }

  public function whitelistFormats($_formatArray){
    $this->_supportedFormats=array_merge($this->_supportedFormats,$_formatArray);
  }

  public function uploadFile($file){
    $backButton="<br><input type=\"submit\" value=\"Back\" <a href=\"#\" onclick=\"history.back();\"></a>";
    if(is_uploaded_file($file['tmp_name'])){
      if(in_array($file['type'],$this->_supportedFormats)){
        if(!is_dir($this->path)){
          mkdir($this->path);
        }
        move_uploaded_file($file['tmp_name'],$this->path.$file['name']);
        echo 'File has been uploaded.';
        echo $backButton;
      }
      else{
          echo 'File format is not supported!';
          echo $backButton;
      }
    }
    else{
      echo 'File was not submitted!';
      echo $backButton;
    }
  }
}
