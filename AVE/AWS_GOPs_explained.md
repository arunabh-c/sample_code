Ref: https://aws.amazon.com/blogs/media/part-1-back-to-basics-gops-explained/


Motivation to compress: uncompressed rates impossible with residential internet.

Resolution	              Uncompressed Bitrate
1280×720 (720p)	             ~ 1.5 Gbps
1920×1080 (1080p)	           ~ 3 Gbps
3180 x 2160 (2160p or 4K)	   ~ 12 Gbps

**2 Types of compression:**

Tempotral Compression: Successive frames only carry pixel difference from previous reference frame. (Reference Frame is called Key Frame)

Spatial Compression: Pixels in same frame can carry only delta info compared to neighboring group of pixels.

**Reasons to not have only 1 key frame:**

1. With 1 key frame impossible to watch video from random points. video un-playable from any point besides first point.
2. Error resiliency. IF error introduce. no way to fix without additional key frame.
3. Scene Change. Scenes also change where most pixels change. Only non-key frames will make it hard. AVE automatically intrpduce Key frame on scene change boundary also known as Scene Change Detection

**GOP** : Distance between 2 key frames measured in number of frames or number of seconds. Real-world GOP vary from 0.5 to 2 secs.

Key Frames also known as **I** or **Intra-coded frames** (Intra- cos compression done within frame amongst pixels/spatial compression). **IDR frames** have subtle differences from I frame but mostly same.
I frames use most amount of bits due to only spatial compression but no temporal compression.

**P Frame (Predicted Frame)** gives difference from previous frame. better at compression. both spatial and temporal compression.

**B Frame (Bi-Directional Predicted Frame)** contain differences from both previous and future frames. Highest compression. Encoder buffers past and future frames before buffering B-frames.

Typical GOP pattern: I B B P B B P B B P B B I

A sequence represented by M, N.

M : distance between 2 I frames (12)
N : Distance between 2 P/I frames (3)

Also note, N = BFrameNum + 1

So (3,12).

Short GOP Length = Lower Compression
High GOP Length = Higher Compression

Low Bitrate movie => Short GOP Length => Poorer video quality

Which type of frame is most important?

One question that I like to ask when interviewing video engineers is, “Which type of frame is the most important?” A common (and perfectly acceptable!) answer is that I-frames are the most important, because without them, the other types of frames would have nothing to base their differences on. But the subtle nuance of this question is that there is no single correct answer. One might just as correctly say that B-frames are the most important because they offer the best compression. After all, what’s the point of video compression if it doesn’t compress the video very well? The purpose of this question isn’t to get the correct answer, it’s to hear the candidate provide their justification for the answer, as that provides a big clue as to how well they understand these fundamental concepts.
