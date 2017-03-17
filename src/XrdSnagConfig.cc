/******************************************************************************/
/*   Produced by Brian Bockelman for University of Nebraska                   */
/******************************************************************************/

#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <memory.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>
#include <sys/stat.h>

#include "XrdVersion.hh"
#include "XrdOuc/XrdOucEnv.hh"
#include "XrdSys/XrdSysError.hh"
#include "XrdSys/XrdSysHeaders.hh"
#include "XrdSys/XrdSysLogger.hh"
#include "XrdSys/XrdSysPlugin.hh"
#include "XrdSys/XrdSysPthread.hh"
#include "XrdSec/XrdSecInterface.hh"

#include "XrdSnag.hh"

/******************************************************************************/
/*                               d e f i n e s                                */
/******************************************************************************/

#define TS_Xeq(x,m)    if (!strcmp(x,var)) return m(Config);

/******************************************************************************/
/*                             C o n f i g u r e                              */
/******************************************************************************/

int XrdSnag::FileSystem::Configure(XrdSysError&, XrdSfsFileSystem*)
{
/*
  Function: Establish configuration at start up time.

  Input:    None.

  Output:   0 upon success or !0 otherwise.
*/

   m_eroute.Emsg("Config", "Configuring SNAG plugin.");

   return 0;
}

