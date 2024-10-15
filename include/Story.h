// Copyright 2024 Vianney Veremme
#ifndef INCLUDE_STORY_H_
#define INCLUDE_STORY_H_

#include <string>
#include <unordered_map>

struct StorySegment {
    std::string description;
    std::unordered_map<int, std::string> choices;
    std::unordered_map<int, int> nextSegmentIds;
};

class Story {
 public:
    int getCurrentSegment() const;
    bool isChoiceValid(int choice);
    void loadStory();
    void printSegment();
    void setCurrentSegment(int segmentId);

 private:
    std::unordered_map<int, StorySegment> storySegments;
    int currentSegmentId;  // New member variable to store the current segment ID
};

#endif  // INCLUDE_STORY_H_
