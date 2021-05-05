class WordLadder{
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        
        Map<String,Boolean> map = new HashMap<>();
        for(String s : wordList){
            map.put(s,false);
        }
        
        if(!map.containsKey(endWord)){
            return 0;
        }
        
        Queue<String> q = new LinkedList<>();
        q.add(beginWord);
        int count = 1;
        
        while(!q.isEmpty()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                String currentWord = q.poll();
                if(currentWord.equals(endWord)){
                    return count;
                }
                // add immediate next words to the queue
                for(int k = 0;k<currentWord.length();k++){
                    for(int j=0;j<26;j++){
                        String newWord = currentWord.substring(0,k)+Character.toString('a'+j)+currentWord.substring(k+1,currentWord.length());
                        
                        if(map.containsKey(newWord) && !map.get(newWord)){
                            map.put(newWord,true);
                            //System.out.println(newWord);
                            q.add(newWord);
                        }
                    }
                    
                }
            }
            count++;
        }
        return 0;
    }
}