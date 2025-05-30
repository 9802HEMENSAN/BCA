# Go-Back-N Sliding Window Protocol

## 1. Introduction to Sliding Window Protocols

- Sliding window protocols are used in computer networking to ensure reliable and efficient data transfer between a sender and a receiver.
- They allow the sender to transmit multiple frames before receiving acknowledgments, improving network bandwidth utilization.
- The "window" represents the number of frames that can be sent without immediate acknowledgement.

## 2. Definition of Go-Back-N Protocol

- Go-Back-N is a type of sliding window protocol where the sender can send up to **N** frames without receiving acknowledgments.
- The receiver accepts frames only in sequence; if a frame is lost or corrupted, it discards that frame and all subsequent frames until the correct frame is retransmitted.

## 3. How Go-Back-N Works

- **Sender Side:**
  - Maintains a window of size **N**, which includes frames that can be sent without acknowledgment.
  - Sends frames within the window and starts a timer for each frame.
  - Upon receiving an acknowledgment (ACK), slides the window forward to include new frames.
  - If a timeout occurs (no ACK received within a set time), resends the timed-out frame and all subsequent frames already sent but not acknowledged.
- **Receiver Side:**
  - Accepts frames only in the correct sequence.
  - Sends an ACK for each frame received in order.
  - Discards out-of-order frames and waits for the expected frame.

## 4. Example (Window Size N = 3)

- Suppose the sender has frames numbered 1 to 10 to send, and the window size is **N = 3**.
- **Step 1:** Sender sends frames 1, 2, 3 (window: 1, 2, 3).
- **Step 2:** Receiver gets frame 1, sends ACK1.
- **Step 3:** Sender receives ACK1, slides window to 2, 3, 4, and sends frame 4.
- **Step 4:** Frame 2 is lost; receiver discards frames 3 and 4 (if received) as they are out of order and does not send ACK2.
- **Step 5:** Sender’s timer for frame 2 expires; it resends frames 2, 3, 4 (window: 2, 3, 4).
- **Step 6:** Receiver gets frame 2, sends ACK2, then gets frame 3, sends ACK3, and so on; sender slides window forward.

## 5. Diagram Description

- In an exam, draw a timeline with two vertical lines: one for the sender, one for the receiver.
- Show arrows from sender to receiver for frames (e.g., 1, 2, 3, then 4).
- Show arrows from receiver to sender for ACKs (e.g., ACK1).
- Indicate the window with brackets or shading (e.g., \[1, 2, 3\] shifts to \[2, 3, 4\]).
- Mark frame 2 as lost (e.g., with an "X") and show retransmission of frames 2, 3, 4.
- Label time steps (e.g., t=0, t=1) and include a key for clarity.

## 6. Comparison with Selective Repeat

- Unlike Selective Repeat, which retransmits only lost frames and allows the receiver to buffer out-of-order frames, Go-Back-N resends all frames from the lost one onward.
- Go-Back-N is simpler to implement but less efficient in high-error networks.

## 7. Advantages

- Simple design and implementation.
- Ensures reliable data transfer through retransmissions.

## 8. Disadvantages

- Inefficient when errors occur, as multiple frames are resent even if some were received correctly.
- Performance decreases in networks with high error rates.

## 9. Conclusion

- Go-Back-N is ideal for networks with low error rates where simplicity is prioritized over efficiency.
- Its sliding window mechanism balances throughput and reliability.