module type S = {
  type publisherMsg;
  type encodedT;
  let publisherMsgToValidJson: publisherMsg => encodedT;
  let publisherMsgFromValidJson: encodedT => publisherMsg;
};