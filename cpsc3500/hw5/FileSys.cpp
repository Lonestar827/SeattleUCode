// CPSC 3500: File System
// Implements the file system commands that are available to the shell.

#include <cstring>
#include <iostream>
#include <unistd.h>
using namespace std;

#include "FileSys.h"
#include "BasicFileSys.h"
#include "Blocks.h"

// mounts the file system
void FileSys::mount(int sock) {
  bfs.mount();
  curr_dir = 1; //by default current directory is home directory, in disk block #1
  fs_sock = sock; //use this socket to receive file system operations from the client and send back response messages
}

// unmounts the file system
void FileSys::unmount() {
  bfs.unmount();
  close(fs_sock);
}

/** make a directory
 * @param name name of the new directory
 * TODO: Implement this
 */
void FileSys::mkdir(const char *name)
{
  //TODO: Implement this

  //Initalize Values
  dirblock_t newBlock, currentBlock;
  short newBlockNum;

  //Make and write the new directory block
  newBlock.magic = DIR_MAGIC_NUM;
  newBlock.num_entries = 0;
  newBlockNum = bfs.get_free_block();
  bfs.write_block(newBlockNum, &newBlock);

  //add block to current directory list
  bfs.read_block(curr_dir, &currentBlock);
  currentBlock.dir_entries[currentBlock.num_entries+1].block_num = newBlockNum;
  //currentBlock.dir_entries[currentBlock.num_entries+1].name = &name;

  //increase number of entries in the current directory
  currentBlock.num_entries++;
  
}

/** switch to a directory
 * The directory must be a subdirectory in the current directory
 * no paths or ".." is allowed
 * @param name the name of the directory
 * TODO: Implement this
 */
void FileSys::cd(const char *name)
{
  //TODO: Implement this

  dirblock_t currentBlock;
  bfs.read_block(curr_dir, &currentBlock);

  for(int i = 0; i < currentBlock.num_entries; i++){

    if(currentBlock.dir_entries[i].name == name){

      curr_dir = currentBlock.dir_entries[i].block_num;

    }

  }

}

/** switch to home directory
 * TODO: Implement this
 */ 
void FileSys::home() 
{
  //TODO: Implement this

  curr_dir = 1;

}

/** Remove a directory
* Directory must be empty before it can be removed
* @param name the name of the directory that needs to be removed
* TODO: Implement this
*/
void FileSys::rmdir(const char *name)
{
  //TODO: Implement this

  dirblock_t currentBlock, toDeleteBlock;
  bfs.read_block(curr_dir, &currentBlock);

  for(int i = 0; i < currentBlock.num_entries; i++){

    if(currentBlock.dir_entries[i].name == name){

      bfs.read_block(currentBlock.dir_entries[i].block_num, &toDeleteBlock);

      if(toDeleteBlock.num_entries == 0){

        bfs.reclaim_block(currentBlock.dir_entries[i].block_num);

        currentBlock.dir_entries[i].block_num = 0;

        currentBlock.num_entries--;

      }else{

        cout << "Files exist here, cannot delete" << endl;

      }

    }

  }
}

/** list the contents of current directory
 * Directories have a '/' suffix such as 'myDir/' files do not have suffix
 * TODO: Implement this
 */
void FileSys::ls()
{
  //TODO: Implement this

  //loop of 0 to num entries

  dirblock_t currBlock;

  bfs.read_block(curr_dir, &currBlock);

  for(int i = 0; i < currBlock.num_entries; i++){

      cout << currBlock.dir_entries[i].name << endl;

  }
}

/** create an empty data file
 * an empty file consists of an inode and no data blocks
 * @param name the name of the new file 
 * TODO: Implement this
 */
void FileSys::create(const char *name)
{
  dirblock_t currentBlock;
  inode_t newInode;
  short newBlockNum;

  bfs.read_block(curr_dir, &currentBlock);

  newInode.magic = INODE_MAGIC_NUM;
  newInode.size = 0;

  newBlockNum = bfs.get_free_block();
  bfs.write_block(newBlockNum, &newInode);

  //currentBlock.dir_entries[currentBlock.num_entries].name = name;
  currentBlock.dir_entries[currentBlock.num_entries].block_num = newBlockNum;
  
}

/** append data to a data file
 * Data should be appended in a manner to first fill the last data block as much as possible and then allocating new block(s) ONLY if more space is needed.
 * @param name the name of the file that will be appened onto
 * @param data the data to be appended onto the file
 * TODO: Implement size check
*/
void FileSys::append(const char *name, const char *data)
{
  //initialize values
  dirblock_t currentBlock;

  short inodeNumber;
  inode_t dataInode;

  short dataNumber;
  datablock_t currentData;

  int dataLength = strlen(data);

  bfs.read_block(curr_dir, &currentBlock);

  for(int i = 0; i < currentBlock.num_entries; i++){

    if(currentBlock.dir_entries[i].name == name){

      if(!isDirectory(currentBlock.dir_entries[i].block_num)){
        
        inodeNumber = currentBlock.dir_entries[i].block_num;

        bfs.read_block(inodeNumber, &dataInode);

        //empty check
        if(dataInode.size == 0){

          dataNumber = bfs.get_free_block();
          //write new datablock to disk
          bfs.write_block(dataNumber, &currentData);
          //increase size of Inode by 1
          dataInode.blocks[dataInode.size] = dataNumber;
          dataInode.size++;

        }

        //size check  

        //appending part
        for(int i = 0; i < dataLength; i++){

          currentData.data[dataInode.size] = data[i];
          dataInode.size++;

        }

      }else
      {

        //cannot append to directory

      }

    }

  }

}

/** display the contents of a data file
 *  when a file is completed print a newline
 * @param name the name of the file in the current directory
 * TODO: Implement this
 */
void FileSys::cat(const char *name)
{
  //TODO: Implement this
}

/** display the first N bytes of the file
 * Print a newline when completed
 * @param name the name of the file to print
 * @param n how many bytes to print, if larger then size of the file, simple print the whole file
 * TODO: Implement this
 */ 
void FileSys::head(const char *name, unsigned int n)
{
  //TODO: Implement this
}

/** delete a data file
 * Reclaims all of its blocks including its Inode
 * Cannot remove directories
 * @param name the file to be removed
 * TODO: Implement this
 */ 
void FileSys::rm(const char *name)
{
  //TODO: Implement this
}

/** display stats about file or directory
 * @param name the name of the file to be scanned
 * TODO: Implement this
 */ 
void FileSys::stat(const char *name)
{
  //TODO: Implement this

  dirblock_t currentBlock;
  bfs.read_block(curr_dir, &currentBlock);

  for(int i = 0; i < currentBlock.num_entries; i++){

    if(currentBlock.dir_entries[i].name == name){

        if(isDirectory(currentBlock.dir_entries[i].block_num)){

          //print out directory stats

        }else
        {

          //print out file stats

        }

    }

  }
  
}

// HELPER FUNCTIONS (optional)

/**Returns true if the file given is a directory (if the Inodes magic number is the directories)
 * @param name the name of the file in question
 * @returns True if a directory, false if otherwise
 * TODO: Implement this
 */
bool FileSys::isDirectory(short blocknum){

  dirblock_t newblock;
  bfs.read_block(blocknum, &newblock);

  if(newblock.magic == DIR_MAGIC_NUM) return true;
  else return false;

}