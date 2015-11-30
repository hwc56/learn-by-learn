
from wicd import dbusmanager
from wicd import misc
from wicd.misc import noneToString, stringToNone, noneToBlankString, to_bool
import gobject
import pango
daemon = wireless = wired = lost_dbus_id = None

def setup_dbus(force=True):
    global daemon, wireless, wired, DBUS_AVAIL, lost_dbus_id
    print "Connecting to daemon..."
    try:
        dbusmanager.connect_to_dbus()
    except DBusException:
        if force:
            print "Can't connect to the daemon, trying to start it automatically..."
            misc.PromptToStartDaemon()
            try:
                dbusmanager.connect_to_dbus()
            except DBusException:
                error(None, _("Could not connect to wicd's D-Bus interface. Check the wicd log for error messages."))
                return False
        else:  
            return False
                
    if lost_dbus_id:
        gobject.source_remove(lost_dbus_id)
        lost_dbus_id = None
    dbus_ifaces = dbusmanager.get_dbus_ifaces()
    daemon = dbus_ifaces['daemon']
    wireless = dbus_ifaces['wireless']
    wired = dbus_ifaces['wired']
    DBUS_AVAIL = True
    print "Connected."
    #minterface();
    return True
def get_wireless_prop(net_id, prop):
    return wireless.GetWirelessProperty(net_id, prop)


def     minterface():
        num_networks = wireless.GetNumberOfNetworks()
        #print   num_networks
        if num_networks > 0:
            skip_never_connect = not daemon.GetShowNeverConnect()
            for x in xrange(0, num_networks):
                if skip_never_connect and misc.to_bool(get_wireless_prop(x,'never')): continue
                tempnet = WirelessNetworkEntry(x)
                print  tempnet

        #encryption_connect(3,"yfa12345!","wpa")
        """
        if wireless.GetWirelessProperty(0, "encryption"):
            print "security"
            set_net_prop(0,"enctype","wpa")
            set_net_prop(0,"key","yfa12345!")
        else:
            set_net_prop(0,"enctype","None")
        connect(0)
        """
        #disconnect(0)
        return  num_networks
def set_net_prop(networkID,option,value):
    wireless.SetWirelessProperty(networkID, option, value)

def     WirelessNetworkEntry(networkID):
                essid = noneToBlankString(wireless.GetWirelessProperty(networkID,"essid"))
                #print "ESSID : " + essid 
                quality = noneToBlankString(wireless.GetWirelessProperty(networkID,'quality'))
                print "ESSID : " + essid + "  Quality: "+quality 
                return   essid+":"+quality;
                 #strength= int(wireless.GetWirelessProperty(networkID,'strength'))
                 #encryption= (wireless.GetWirelessProperty(networkID,'encryption'))
                 #encryption_method= (wireless.GetWirelessProperty(networkID,'encryption_method'))
                 #channel= (wireless.GetWirelessProperty(networkID,'channel'))
def encryption_connect(networkid,password,encrytype):
    if wireless.GetWirelessProperty(networkid, "encryption"):
            print "security"
            set_net_prop(networkid,"enctype",encrytype)
            set_net_prop(networkid,"key",password)
    else:
            set_net_prop(networkid,"enctype","None")
    connect(networkid)


def connect( networkid):
           wireless.ConnectWireless(networkid, reply_handler=handler,error_handler=handler)


def disconnect( networkid):
           wireless.DisconnectWireless(reply_handler=handler,error_handler=handler)




def handler(*args):
        print  "ssss"
"""
def connect_status():
    daemon.UpdateState()
    if  DBUS_AVAIL
        do_status_update(*daemon.GetConnectionStatus())

def do_status_update(state,info):
    if state == misc.WIRED:
       print _('Connected to wired network (IP: $A)').replace('$A', info[0])
    elif state == misc.WIRELESS:
        print _('Connected to $A at $B (IP: $C)').replace('$A', info[1]).replace('$B', daemon.FormatSignalForPrinting(info[2])).replace('$C', info[0]))
    elif state == misc.CONNECTING:
        if info[0] == "wireless":
            stat = wireless.CheckWirelessConnectingMessage()
            print info[1]+ stat;
        elif info[0] == "wired":
            print  "Wired Network:" + wired.CheckWiredConnectingMessage()
    elif state in (misc.SUSPENDED, misc.NOT_CONNECTED):
    print  "Not connected"
    return True
"""

""" def check_encryption_valid( networkid, entry):
        # Make sure that encryption settings are properly filled in. 
        # Make sure no entries are left blank
        if entry:
            encryption_info = entry
            for entry_info in encryption_info.itervalues():
                if entry_info[0].entry.get_text() == "" and \
                   entry_info[1] == 'required':
                    error(self.window, "%s (%s)" % (_('Required encryption information is missing.'),
                                             entry_info[0].label.get_label())
                          )
                    return False
        # Make sure the checkbox is checked when it should be
        elif not entry.chkbox_encryption.get_active() and \
             wireless.GetWirelessProperty(networkid, "encryption"):
           error(self.window, _('This network requires encryption to be enabled.'))
            return False
        return True
        """
