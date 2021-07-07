// Created on Oct 3 23:19 2018
// author: grendach@gmail.com
// Simple Golang code for creating a *.tgz archive for a files or directories.

// Before running this program you need to add to your env variables next:
// "TARGET_FILE" (name of your archive) and "SOURCE_PATH" (path to the files or directory that you want to archive)
// for Linux please run next command:
// export SOURCE_PATH=<path/to/your/files/that/you/want/to/archive/>
// export TARGET_FILE=backup.tgz (backup.tgz - name of your backup.)

package main

import (
	"archive/tar"
	"compress/gzip"
	"fmt"
	"io"
	"log"
	"os"
)

//creating an interface for compression
type Compress interface {
	TgzCreate(string, string)
}

//Structure for compression interfaces
type Structure struct {
	outFilePath string
	sourcePath  string
}

func handleError(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func TarCreate(path string, tw *tar.Writer, fi os.FileInfo) {
	fr, err := os.Open(path)
	handleError(err)
	defer fr.Close()

	h := new(tar.Header)
	h.Name = path
	h.Size = fi.Size()
	h.Mode = int64(fi.Mode())
	h.ModTime = fi.ModTime()

	err = tw.WriteHeader(h)
	handleError(err)

	_, err = io.Copy(tw, fr)
	handleError(err)

}

func IterDirectory(dirPath string, tw *tar.Writer) {
	info, err := os.Stat(dirPath)

	if err != nil {
		handleError(err)
	}

	if info.IsDir() {
		dir, err := os.Open(dirPath)
		handleError(err)
		defer dir.Close()

		files, err := dir.Readdir(0)
		handleError(err)
		for _, file := range files {
			curPath := dirPath + "/" + file.Name()
			if file.IsDir() {
				IterDirectory(curPath, tw)
				fmt.Printf("adding...%s\n", curPath)
			} else {
				fmt.Printf("adding...%s\n", curPath)
				TarCreate(curPath, tw, file)
			}
		}
	} else {
		fmt.Printf("adding ...%s\n", dirPath)
		TarCreate(dirPath, tw, info)
	}
}
func (s *Structure) TgzCreate() {
	//file write
	fw, err := os.Create(s.outFilePath)
	handleError(err)
	defer fw.Close()

	//gzip write
	gw := gzip.NewWriter(fw)
	defer gw.Close()

	//tar write
	tw := tar.NewWriter(gw)
	defer tw.Close()

	IterDirectory(s.sourcePath, tw)

	fmt.Println(fw.Name(), "successfully created")
	fmt.Println("Backup finished!")

}

func main() {
	s1 := Structure{
		os.Getenv("TARGET_FILE"), //set up target compressed file as env var
		os.Getenv("SOURCE_PATH"), //set up  backup dir as env var
	}

	s1.TgzCreate()

}
