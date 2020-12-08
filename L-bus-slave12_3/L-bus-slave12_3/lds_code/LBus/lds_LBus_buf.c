#include "lds_LBus_buf.h"

//stLBusRecBuf_t gstLBusRecBuf;
//stLBusSendBuf_t gstLBusSendBuf;

/**
  * @brief      Send DALI cmd if there is frame to be sent
  *
  * @param      None
  *
  * @return     None
  */
  /*
void dali_sendMultCmd_process(void){
  if(gstLBusSendBuf.cCurrentIndex != gstLBusSendBuf.cFinalIndex){
    if(FALSE == dali_bit_getSendReadyFlagStat()){
      stDaliSendBuf.cCurrentSendBufNum++;
      if(DALI_SEND_BUF_NUM_MAX <= stDaliSendBuf.cCurrentSendBufNum){
        stDaliSendBuf.cCurrentSendBufNum = 0;
      }
      dali_bit_encode(stDaliSendBuf.atDaliSend[stDaliSendBuf.cCurrentSendBufNum].uiFrame,
                      stDaliSendBuf.atDaliSend[stDaliSendBuf.cCurrentSendBufNum].eFrameType,
                      stDaliSendBuf.atDaliSend[stDaliSendBuf.cCurrentSendBufNum].eBitLen,
                      stDaliSendBuf.atDaliSend[stDaliSendBuf.cCurrentSendBufNum].ePriority,
                      stDaliSendBuf.atDaliSend[stDaliSendBuf.cCurrentSendBufNum].cRepeat);
    }
  }
}
*/
