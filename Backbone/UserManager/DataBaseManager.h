//
// Created by eduardo on 01/05/18.
//

#ifndef USERMANAGER_USERMANAGER_H
#define USERMANAGER_USERMANAGER_H

#include "DataManager/JSONManager.h"
#include "XMLManager/XMLManager.h"
#include "XMLManager/XMLParts.h"
#include "HashFunct/HashClass.h"
#include "AlphabeticTree/AlphaTree.h"
#include "DataStructs/DataStructures.h"
#include "../AVLTree/AVLTree.h"

#include "string"
#include "BTree/BTree.h"

class DataBaseManager {
private:
    //User database manager
    JSONManager* JManager = new JSONManager("/home/eduardo/Documents/Datos II/Proyecto 2/Backbone/UserManager/cmake-build-debug/data.json");
    //Song database manager
    JSONManager* SongManager = new JSONManager("/home/eduardo/Documents/Datos II/Proyecto 2/Backbone/UserManager/cmake-build-debug/songs.json");
    //XML Interpreter and builder
    XMLManager* XManager;
    //Class in charge of hashing the passwords
    HashClass Hasher;
    //Binary Search Tree for alphabetical arrangement
    AlphaTree UsersTree;
    //BTree for song name arrangement
    BTree* songNames = new BTree(3);
    //Single list for album name arrangement
    SingleList<string> albumList;
    //AVL Tree for artist name arrangement
    AVLTree* artistTree = NULL;
    //User thats logged in at the moment
    string currentUser;
    //First song ind
    int firstSong = 0;

public:
    DataBaseManager();
//------------------------------------------Server functions--------------------------------------------------------
/***
 * Function in charge of receiving the data through the server socket
 * @param data (XML from server)
 */
    string recieveData(string data);
/***
 * Function in charge of loading all data to the respective trees when the server is initialized
 */
    void loadTree();
    /***
     * Function that checks if a friend is in the friend list of an user
     * @param user (User that gets checked)
     * @param newFriend (Friend being checked)
     * @return 0 or 1
     */
    bool hasFriend(json user, string newFriend);
    /***
     * Returns a string with all the songs, arranged in chronological order
     * @return string
     */
    string makeSongStream(int page);
//------------------------------------------User management---------------------------------------------------------

    /***
     * Registers user in data
     * @param data (CDATA from server)
     * @return
     */
    string registerUser(string data);
    /***
     * Checks if a user exist and if the password is right
     * @param data (CDATA from server)
     * @return
     */
    string validateUser(string data);
    /***
     * Adds a message to the pending message list
     * @param data
     * @return
     */
    string recommendSong(string data);
    /***
     * Returns a basic answer XML with the user data and the song data
     * @param opnum
     * @return
     */
    string makeAnswerXML(int opnum);
    /***
     *
     *Adds a friend to the friends list
     * @param data
     * @return
     *
     */
    string addFriend(string data);

//------------------------------------------Song management---------------------------------------------------------
/***
 * Registers a new song
 * @param data (CDATA from server)
 * @return
 */
    string registerSong(string data);
    /***
     * Searches a song by name and returns the song data if the song exists
     * @param data
     * @return
     */
    string searchSongByName(string data);
    /***
     * Deletes a song from memory
     * @param data
     * @return
     */
    string deleteSong(string data);
    /***
     * Modifies song metadata
     * @param data
     * @return
     */
    string modifySong(string data);

};


#endif //USERMANAGER_USERMANAGER_H
