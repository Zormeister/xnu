/* iig(DriverKit-73.100.4) generated from IOUserServer.iig */

#undef	IIG_IMPLEMENTATION
#define	IIG_IMPLEMENTATION 	IOUserServer.iig

#include <DriverKit/IOReturn.h>
#include <DriverKit/IOUserServer.h>

/* @iig implementation */
#include <IOKit/IOUserServer.h>
/* @iig end */


struct IOUserServer_Create_Msg_Content
{
    IORPCMessage __hdr;
    OSObjectRef  __object;
    const char *  name;
    char __name[64];
    uint64_t  tag;
    uint64_t  options;
};
#pragma pack(4)
struct IOUserServer_Create_Msg
{
    IORPCMessageMach           mach;
    mach_msg_port_descriptor_t __object__descriptor;
    IOUserServer_Create_Msg_Content content;
};
#pragma pack()
#define IOUserServer_Create_Msg_ObjRefs (1)

struct IOUserServer_Create_Rpl_Content
{
    IORPCMessage __hdr;
    OSObjectRef  server;
};
#pragma pack(4)
struct IOUserServer_Create_Rpl
{
    IORPCMessageMach           mach;
    mach_msg_port_descriptor_t server__descriptor;
    IOUserServer_Create_Rpl_Content content;
};
#pragma pack()
#define IOUserServer_Create_Rpl_ObjRefs (1)


typedef union
{
    const IORPC rpc;
    struct
    {
        const struct IOUserServer_Create_Msg * message;
        struct IOUserServer_Create_Rpl       * reply;
        uint32_t sendSize;
        uint32_t replySize;
    };
}
IOUserServer_Create_Invocation;
struct IOUserServer_Exit_Msg_Content
{
    IORPCMessage __hdr;
    OSObjectRef  __object;
    const char *  reason;
    char __reason[1024];
};
#pragma pack(4)
struct IOUserServer_Exit_Msg
{
    IORPCMessageMach           mach;
    mach_msg_port_descriptor_t __object__descriptor;
    IOUserServer_Exit_Msg_Content content;
};
#pragma pack()
#define IOUserServer_Exit_Msg_ObjRefs (1)

struct IOUserServer_Exit_Rpl_Content
{
    IORPCMessage __hdr;
};
#pragma pack(4)
struct IOUserServer_Exit_Rpl
{
    IORPCMessageMach           mach;
    IOUserServer_Exit_Rpl_Content content;
};
#pragma pack()
#define IOUserServer_Exit_Rpl_ObjRefs (0)


typedef union
{
    const IORPC rpc;
    struct
    {
        const struct IOUserServer_Exit_Msg * message;
        struct IOUserServer_Exit_Rpl       * reply;
        uint32_t sendSize;
        uint32_t replySize;
    };
}
IOUserServer_Exit_Invocation;
struct IOUserServer_LoadModule_Msg_Content
{
    IORPCMessage __hdr;
    OSObjectRef  __object;
    const char *  path;
    char __path[1024];
};
#pragma pack(4)
struct IOUserServer_LoadModule_Msg
{
    IORPCMessageMach           mach;
    mach_msg_port_descriptor_t __object__descriptor;
    IOUserServer_LoadModule_Msg_Content content;
};
#pragma pack()
#define IOUserServer_LoadModule_Msg_ObjRefs (1)

struct IOUserServer_LoadModule_Rpl_Content
{
    IORPCMessage __hdr;
};
#pragma pack(4)
struct IOUserServer_LoadModule_Rpl
{
    IORPCMessageMach           mach;
    IOUserServer_LoadModule_Rpl_Content content;
};
#pragma pack()
#define IOUserServer_LoadModule_Rpl_ObjRefs (0)


typedef union
{
    const IORPC rpc;
    struct
    {
        const struct IOUserServer_LoadModule_Msg * message;
        struct IOUserServer_LoadModule_Rpl       * reply;
        uint32_t sendSize;
        uint32_t replySize;
    };
}
IOUserServer_LoadModule_Invocation;
#if !KERNEL
extern OSMetaClass * gOSContainerMetaClass;
extern OSMetaClass * gOSDataMetaClass;
extern OSMetaClass * gOSNumberMetaClass;
extern OSMetaClass * gOSStringMetaClass;
extern OSMetaClass * gOSBooleanMetaClass;
extern OSMetaClass * gOSDictionaryMetaClass;
extern OSMetaClass * gOSArrayMetaClass;
extern OSMetaClass * gIODispatchQueueMetaClass;
extern OSMetaClass * gIOMemoryDescriptorMetaClass;
extern OSMetaClass * gIOBufferMemoryDescriptorMetaClass;
extern OSMetaClass * gIOUserClientMetaClass;
#endif /* !KERNEL */

#if !KERNEL

#define IOUserServer_QueueNames  ""

#define IOUserServer_MethodNames  ""

#define IOUserServerMetaClass_MethodNames  ""

struct OSClassDescription_IOUserServer_t
{
    OSClassDescription base;
    uint64_t           methodOptions[2 * 0];
    uint64_t           metaMethodOptions[2 * 0];
    char               queueNames[sizeof(IOUserServer_QueueNames)];
    char               methodNames[sizeof(IOUserServer_MethodNames)];
    char               metaMethodNames[sizeof(IOUserServerMetaClass_MethodNames)];
};

const struct OSClassDescription_IOUserServer_t
OSClassDescription_IOUserServer =
{
    .base =
    {
        .descriptionSize         = sizeof(OSClassDescription_IOUserServer_t),
        .name                    = "IOUserServer",
        .superName               = "IOService",
        .flags                   = 1*kOSClassCanRemote,
        .methodOptionsSize       = 2 * sizeof(uint64_t) * 0,
        .metaMethodOptionsSize   = 2 * sizeof(uint64_t) * 0,
        .queueNamesSize       = sizeof(IOUserServer_QueueNames),
        .methodNamesSize         = sizeof(IOUserServer_MethodNames),
        .metaMethodNamesSize     = sizeof(IOUserServerMetaClass_MethodNames),
        .methodOptionsOffset     = __builtin_offsetof(struct OSClassDescription_IOUserServer_t, methodOptions),
        .metaMethodOptionsOffset = __builtin_offsetof(struct OSClassDescription_IOUserServer_t, metaMethodOptions),
        .queueNamesOffset     = __builtin_offsetof(struct OSClassDescription_IOUserServer_t, queueNames),
        .methodNamesOffset       = __builtin_offsetof(struct OSClassDescription_IOUserServer_t, methodNames),
        .metaMethodNamesOffset   = __builtin_offsetof(struct OSClassDescription_IOUserServer_t, metaMethodNames),
    },
    .methodOptions =
    {
    },
    .metaMethodOptions =
    {
    },
    .queueNames      = IOUserServer_QueueNames,
    .methodNames     = IOUserServer_MethodNames,
    .metaMethodNames = IOUserServerMetaClass_MethodNames,
};

OSMetaClass * gIOUserServerMetaClass;

static kern_return_t
IOUserServer_New(OSMetaClass * instance);

const OSClassLoadInformation
IOUserServer_Class = 
{
    .version           = 1,
    .description       = &OSClassDescription_IOUserServer.base,
    .instanceSize      = sizeof(IOUserServer),

    .metaPointer       = &gIOUserServerMetaClass,
    .New               = &IOUserServer_New,
};

extern const void * const
gIOUserServer_Declaration;
const void * const
gIOUserServer_Declaration
__attribute__((visibility("hidden"),section("__DATA_CONST,__osclassinfo,regular,no_dead_strip")))
    = &IOUserServer_Class;

static kern_return_t
IOUserServer_New(OSMetaClass * instance)
{
    if (!new(instance) IOUserServerMetaClass) return (kIOReturnNoMemory);
    return (kIOReturnSuccess);
}

kern_return_t
IOUserServerMetaClass::New(OSObject * instance)
{
    if (!new(instance) IOUserServer) return (kIOReturnNoMemory);
    return (kIOReturnSuccess);
}

#endif /* !KERNEL */

kern_return_t
IOUserServer::Dispatch(const IORPC rpc)
{
    return _Dispatch(this, rpc);
}

kern_return_t
IOUserServer::_Dispatch(IOUserServer * self, const IORPC rpc)
{
    kern_return_t ret = kIOReturnUnsupported;
    IORPCMessage * msg = IORPCMessageFromMach(rpc.message, false);

    switch (msg->msgid)
    {
        case IOUserServer_Exit_ID:
        {
            union {
                kern_return_t (IOUserServer::*fIn)(IOUserServer_Exit_Args);
                IOUserServer::Exit_Handler handler;
            } map;
            map.fIn = &IOUserServer::Exit_Impl;
            ret = IOUserServer::Exit_Invoke(rpc, self, map.handler);
            break;
        }
        case IOUserServer_LoadModule_ID:
        {
            union {
                kern_return_t (IOUserServer::*fIn)(IOUserServer_LoadModule_Args);
                IOUserServer::LoadModule_Handler handler;
            } map;
            map.fIn = &IOUserServer::LoadModule_Impl;
            ret = IOUserServer::LoadModule_Invoke(rpc, self, map.handler);
            break;
        }

        default:
            ret = IOService::_Dispatch(self, rpc);
            break;
    }

    return (ret);
}

#if KERNEL
kern_return_t
IOUserServer::MetaClass::Dispatch(const IORPC rpc)
{
#else /* KERNEL */
kern_return_t
IOUserServerMetaClass::Dispatch(const IORPC rpc)
{
#endif /* !KERNEL */

    kern_return_t ret = kIOReturnUnsupported;
    IORPCMessage * msg = IORPCMessageFromMach(rpc.message, false);

    switch (msg->msgid)
    {
#if KERNEL
        case IOUserServer_Create_ID:
            ret = IOUserServer::Create_Invoke(rpc, &IOUserServer::Create_Impl);
            break;
#endif /* !KERNEL */

        default:
            ret = OSMetaClassBase::Dispatch(rpc);
            break;
    }

    return (ret);
}

kern_return_t
IOUserServer::Create(
        const char * name,
        uint64_t tag,
        uint64_t options,
        IOUserServer ** server)
{
    kern_return_t ret;
    union
    {
        IOUserServer_Create_Msg msg;
        struct
        {
            IOUserServer_Create_Rpl rpl;
            mach_msg_max_trailer_t trailer;
        } rpl;
    } buf;
    struct IOUserServer_Create_Msg * msg = &buf.msg;
    struct IOUserServer_Create_Rpl * rpl = &buf.rpl.rpl;

    memset(msg, 0, sizeof(struct IOUserServer_Create_Msg));
    msg->mach.msgh.msgh_id   = kIORPCVersion190615;
    msg->mach.msgh.msgh_size = sizeof(*msg);
    msg->content.__hdr.flags = 0*kIORPCMessageOneway
                             | 0*kIORPCMessageSimpleReply
                             | 0*kIORPCMessageLocalHost
                             | 0*kIORPCMessageOnqueue;
    msg->content.__hdr.msgid = IOUserServer_Create_ID;
    msg->content.__object = (OSObjectRef) OSTypeID(IOUserServer);
    msg->content.__hdr.objectRefs = IOUserServer_Create_Msg_ObjRefs;
    msg->mach.msgh_body.msgh_descriptor_count = 1;

    msg->__object__descriptor.type = MACH_MSG_PORT_DESCRIPTOR;

    msg->content.name = name;

    strlcpy(&msg->content.__name[0], name, sizeof(msg->content.__name));

    msg->content.tag = tag;

    msg->content.options = options;

    IORPC rpc = { .message = &buf.msg.mach, .sendSize = sizeof(buf.msg), .reply = &buf.rpl.rpl.mach, .replySize = sizeof(buf.rpl) };
    ret = OSMTypeID(IOUserServer)->Invoke(rpc);

    if (kIOReturnSuccess == ret)
    do {
        {
            if (rpl->mach.msgh.msgh_size                  != sizeof(*rpl)) { ret = kIOReturnIPCError; break; };
            if (rpl->content.__hdr.msgid                  != IOUserServer_Create_ID) { ret = kIOReturnIPCError; break; };
            if (rpl->mach.msgh_body.msgh_descriptor_count != 1) { ret = kIOReturnIPCError; break; };
            if (IOUserServer_Create_Rpl_ObjRefs   != rpl->content.__hdr.objectRefs) { ret = kIOReturnIPCError; break; };
        }
    }
    while (false);
    if (kIOReturnSuccess == ret)
    {
        *server = OSDynamicCast(IOUserServer, (OSObject *) rpl->content.server);
        if (rpl->content.server && !*server) ret = kIOReturnBadArgument;
    }


    return (ret);
}

kern_return_t
IOUserServer::Exit(
        const char * reason,
        OSDispatchMethod supermethod)
{
    kern_return_t ret;
    union
    {
        IOUserServer_Exit_Msg msg;
        struct
        {
            IOUserServer_Exit_Rpl rpl;
            mach_msg_max_trailer_t trailer;
        } rpl;
    } buf;
    struct IOUserServer_Exit_Msg * msg = &buf.msg;
    struct IOUserServer_Exit_Rpl * rpl = &buf.rpl.rpl;

    memset(msg, 0, sizeof(struct IOUserServer_Exit_Msg));
    msg->mach.msgh.msgh_id   = kIORPCVersion190615;
    msg->mach.msgh.msgh_size = sizeof(*msg);
    msg->content.__hdr.flags = 0*kIORPCMessageOneway
                             | 1*kIORPCMessageSimpleReply
                             | 0*kIORPCMessageLocalHost
                             | 0*kIORPCMessageOnqueue;
    msg->content.__hdr.msgid = IOUserServer_Exit_ID;
    msg->content.__object = (OSObjectRef) this;
    msg->content.__hdr.objectRefs = IOUserServer_Exit_Msg_ObjRefs;
    msg->mach.msgh_body.msgh_descriptor_count = 1;

    msg->__object__descriptor.type = MACH_MSG_PORT_DESCRIPTOR;

    msg->content.reason = reason;

    strlcpy(&msg->content.__reason[0], reason, sizeof(msg->content.__reason));

    IORPC rpc = { .message = &buf.msg.mach, .sendSize = sizeof(buf.msg), .reply = &buf.rpl.rpl.mach, .replySize = sizeof(buf.rpl) };
    if (supermethod) ret = supermethod((OSObject *)this, rpc);
    else             ret = ((OSObject *)this)->Invoke(rpc);

    if (kIOReturnSuccess == ret)
    do {
        {
            if (rpl->mach.msgh.msgh_size                  != sizeof(*rpl)) { ret = kIOReturnIPCError; break; };
            if (rpl->content.__hdr.msgid                  != IOUserServer_Exit_ID) { ret = kIOReturnIPCError; break; };
            if (rpl->mach.msgh_body.msgh_descriptor_count != 0) { ret = kIOReturnIPCError; break; };
            if (IOUserServer_Exit_Rpl_ObjRefs   != rpl->content.__hdr.objectRefs) { ret = kIOReturnIPCError; break; };
        }
    }
    while (false);
    if (kIOReturnSuccess == ret)
    {
    }


    return (ret);
}

kern_return_t
IOUserServer::LoadModule(
        const char * path,
        OSDispatchMethod supermethod)
{
    kern_return_t ret;
    union
    {
        IOUserServer_LoadModule_Msg msg;
        struct
        {
            IOUserServer_LoadModule_Rpl rpl;
            mach_msg_max_trailer_t trailer;
        } rpl;
    } buf;
    struct IOUserServer_LoadModule_Msg * msg = &buf.msg;
    struct IOUserServer_LoadModule_Rpl * rpl = &buf.rpl.rpl;

    memset(msg, 0, sizeof(struct IOUserServer_LoadModule_Msg));
    msg->mach.msgh.msgh_id   = kIORPCVersion190615;
    msg->mach.msgh.msgh_size = sizeof(*msg);
    msg->content.__hdr.flags = 0*kIORPCMessageOneway
                             | 1*kIORPCMessageSimpleReply
                             | 0*kIORPCMessageLocalHost
                             | 0*kIORPCMessageOnqueue;
    msg->content.__hdr.msgid = IOUserServer_LoadModule_ID;
    msg->content.__object = (OSObjectRef) this;
    msg->content.__hdr.objectRefs = IOUserServer_LoadModule_Msg_ObjRefs;
    msg->mach.msgh_body.msgh_descriptor_count = 1;

    msg->__object__descriptor.type = MACH_MSG_PORT_DESCRIPTOR;

    msg->content.path = path;

    strlcpy(&msg->content.__path[0], path, sizeof(msg->content.__path));

    IORPC rpc = { .message = &buf.msg.mach, .sendSize = sizeof(buf.msg), .reply = &buf.rpl.rpl.mach, .replySize = sizeof(buf.rpl) };
    if (supermethod) ret = supermethod((OSObject *)this, rpc);
    else             ret = ((OSObject *)this)->Invoke(rpc);

    if (kIOReturnSuccess == ret)
    do {
        {
            if (rpl->mach.msgh.msgh_size                  != sizeof(*rpl)) { ret = kIOReturnIPCError; break; };
            if (rpl->content.__hdr.msgid                  != IOUserServer_LoadModule_ID) { ret = kIOReturnIPCError; break; };
            if (rpl->mach.msgh_body.msgh_descriptor_count != 0) { ret = kIOReturnIPCError; break; };
            if (IOUserServer_LoadModule_Rpl_ObjRefs   != rpl->content.__hdr.objectRefs) { ret = kIOReturnIPCError; break; };
        }
    }
    while (false);
    if (kIOReturnSuccess == ret)
    {
    }


    return (ret);
}

kern_return_t
IOUserServer::Create_Invoke(const IORPC _rpc,
        Create_Handler func)
{
    IOUserServer_Create_Invocation rpc = { _rpc };
    kern_return_t ret;

    if (IOUserServer_Create_Msg_ObjRefs != rpc.message->content.__hdr.objectRefs) return (kIOReturnIPCError);
    if (strnlen(&rpc.message->content.__name[0], sizeof(rpc.message->content.__name)) >= sizeof(rpc.message->content.__name)) return kIOReturnBadArgument;

    ret = (*func)(        
        &rpc.message->content.__name[0],
        rpc.message->content.tag,
        rpc.message->content.options,
        (IOUserServer **)&rpc.reply->content.server);

    if (kIOReturnSuccess != ret) return (ret);

    rpc.reply->content.__hdr.msgid = IOUserServer_Create_ID;
    rpc.reply->content.__hdr.flags = kIORPCMessageOneway;
    rpc.reply->mach.msgh.msgh_id   = kIORPCVersion190615Reply;
    rpc.reply->mach.msgh.msgh_size = sizeof(*rpc.reply);
    rpc.reply->mach.msgh_body.msgh_descriptor_count = 1;
    rpc.reply->content.__hdr.objectRefs = IOUserServer_Create_Rpl_ObjRefs;
    rpc.reply->server__descriptor.type = MACH_MSG_PORT_DESCRIPTOR;

    return (ret);
}

kern_return_t
IOUserServer::Exit_Invoke(const IORPC _rpc,
        OSMetaClassBase * target,
        Exit_Handler func)
{
    IOUserServer_Exit_Invocation rpc = { _rpc };
    kern_return_t ret;

    if (IOUserServer_Exit_Msg_ObjRefs != rpc.message->content.__hdr.objectRefs) return (kIOReturnIPCError);
    if (strnlen(&rpc.message->content.__reason[0], sizeof(rpc.message->content.__reason)) >= sizeof(rpc.message->content.__reason)) return kIOReturnBadArgument;

    ret = (*func)(target,        
        &rpc.message->content.__reason[0]);

    if (kIOReturnSuccess != ret) return (ret);

    rpc.reply->content.__hdr.msgid = IOUserServer_Exit_ID;
    rpc.reply->content.__hdr.flags = kIORPCMessageOneway;
    rpc.reply->mach.msgh.msgh_id   = kIORPCVersion190615Reply;
    rpc.reply->mach.msgh.msgh_size = sizeof(*rpc.reply);
    rpc.reply->mach.msgh_body.msgh_descriptor_count = 0;
    rpc.reply->content.__hdr.objectRefs = IOUserServer_Exit_Rpl_ObjRefs;

    return (ret);
}

kern_return_t
IOUserServer::LoadModule_Invoke(const IORPC _rpc,
        OSMetaClassBase * target,
        LoadModule_Handler func)
{
    IOUserServer_LoadModule_Invocation rpc = { _rpc };
    kern_return_t ret;

    if (IOUserServer_LoadModule_Msg_ObjRefs != rpc.message->content.__hdr.objectRefs) return (kIOReturnIPCError);
    if (strnlen(&rpc.message->content.__path[0], sizeof(rpc.message->content.__path)) >= sizeof(rpc.message->content.__path)) return kIOReturnBadArgument;

    ret = (*func)(target,        
        &rpc.message->content.__path[0]);

    if (kIOReturnSuccess != ret) return (ret);

    rpc.reply->content.__hdr.msgid = IOUserServer_LoadModule_ID;
    rpc.reply->content.__hdr.flags = kIORPCMessageOneway;
    rpc.reply->mach.msgh.msgh_id   = kIORPCVersion190615Reply;
    rpc.reply->mach.msgh.msgh_size = sizeof(*rpc.reply);
    rpc.reply->mach.msgh_body.msgh_descriptor_count = 0;
    rpc.reply->content.__hdr.objectRefs = IOUserServer_LoadModule_Rpl_ObjRefs;

    return (ret);
}



