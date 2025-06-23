/* iig(DriverKit-73.100.4) generated from IOUserClient.iig */

#undef	IIG_IMPLEMENTATION
#define	IIG_IMPLEMENTATION 	IOUserClient.iig

#include <DriverKit/IOReturn.h>
#include <DriverKit/IOUserClient.h>

/* @iig implementation */
#include <DriverKit/IOBufferMemoryDescriptor.h>
/* @iig end */


struct IOUserClient_AsyncCompletion_Msg_Content
{
    IORPCMessage __hdr;
    OSObjectRef  __object;
    OSObjectRef  action;
    IOReturn  status;
    const unsigned long long *  asyncData;
    unsigned long long __asyncData[16];
    uint32_t  asyncDataCount;
};
#pragma pack(4)
struct IOUserClient_AsyncCompletion_Msg
{
    IORPCMessageMach           mach;
    mach_msg_port_descriptor_t __object__descriptor;
    mach_msg_port_descriptor_t action__descriptor;
    IOUserClient_AsyncCompletion_Msg_Content content;
};
#pragma pack()
#define IOUserClient_AsyncCompletion_Msg_ObjRefs (2)

struct IOUserClient_AsyncCompletion_Rpl_Content
{
    IORPCMessage __hdr;
};
#pragma pack(4)
struct IOUserClient_AsyncCompletion_Rpl
{
    IORPCMessageMach           mach;
    IOUserClient_AsyncCompletion_Rpl_Content content;
};
#pragma pack()
#define IOUserClient_AsyncCompletion_Rpl_ObjRefs (0)


typedef union
{
    const IORPC rpc;
    struct
    {
        const struct IOUserClient_AsyncCompletion_Msg * message;
        struct IOUserClient_AsyncCompletion_Rpl       * reply;
        uint32_t sendSize;
        uint32_t replySize;
    };
}
IOUserClient_AsyncCompletion_Invocation;
struct IOUserClient_CopyClientMemoryForType_Msg_Content
{
    IORPCMessage __hdr;
    OSObjectRef  __object;
    uint64_t  type;
};
#pragma pack(4)
struct IOUserClient_CopyClientMemoryForType_Msg
{
    IORPCMessageMach           mach;
    mach_msg_port_descriptor_t __object__descriptor;
    IOUserClient_CopyClientMemoryForType_Msg_Content content;
};
#pragma pack()
#define IOUserClient_CopyClientMemoryForType_Msg_ObjRefs (1)

struct IOUserClient_CopyClientMemoryForType_Rpl_Content
{
    IORPCMessage __hdr;
    OSObjectRef  memory;
    unsigned long long  options;
};
#pragma pack(4)
struct IOUserClient_CopyClientMemoryForType_Rpl
{
    IORPCMessageMach           mach;
    mach_msg_port_descriptor_t memory__descriptor;
    IOUserClient_CopyClientMemoryForType_Rpl_Content content;
};
#pragma pack()
#define IOUserClient_CopyClientMemoryForType_Rpl_ObjRefs (1)


typedef union
{
    const IORPC rpc;
    struct
    {
        const struct IOUserClient_CopyClientMemoryForType_Msg * message;
        struct IOUserClient_CopyClientMemoryForType_Rpl       * reply;
        uint32_t sendSize;
        uint32_t replySize;
    };
}
IOUserClient_CopyClientMemoryForType_Invocation;
struct IOUserClient__ExternalMethod_Msg_Content
{
    IORPCMessage __hdr;
    OSObjectRef  __object;
    OSData *  structureInput;
    OSObjectRef  structureInputDescriptor;
    OSObjectRef  structureOutputDescriptor;
    OSObjectRef  completion;
    uint64_t  selector;
    const unsigned long long *  scalarInput;
    unsigned long long __scalarInput[16];
    uint32_t  scalarInputCount;
    unsigned int  scalarOutputCount;
    uint64_t  structureOutputMaximumSize;
};
#pragma pack(4)
struct IOUserClient__ExternalMethod_Msg
{
    IORPCMessageMach           mach;
    mach_msg_port_descriptor_t __object__descriptor;
    mach_msg_ool_descriptor_t  structureInput__descriptor;
    mach_msg_port_descriptor_t structureInputDescriptor__descriptor;
    mach_msg_port_descriptor_t structureOutputDescriptor__descriptor;
    mach_msg_port_descriptor_t completion__descriptor;
    IOUserClient__ExternalMethod_Msg_Content content;
};
#pragma pack()
#define IOUserClient__ExternalMethod_Msg_ObjRefs (5)

struct IOUserClient__ExternalMethod_Rpl_Content
{
    IORPCMessage __hdr;
    OSData *  structureOutput;
    unsigned long long *  scalarOutput;
    unsigned long long __scalarOutput[16];
    unsigned int  scalarOutputCount;
};
#pragma pack(4)
struct IOUserClient__ExternalMethod_Rpl
{
    IORPCMessageMach           mach;
    mach_msg_ool_descriptor_t  structureOutput__descriptor;
    IOUserClient__ExternalMethod_Rpl_Content content;
};
#pragma pack()
#define IOUserClient__ExternalMethod_Rpl_ObjRefs (1)


typedef union
{
    const IORPC rpc;
    struct
    {
        const struct IOUserClient__ExternalMethod_Msg * message;
        struct IOUserClient__ExternalMethod_Rpl       * reply;
        uint32_t sendSize;
        uint32_t replySize;
    };
}
IOUserClient__ExternalMethod_Invocation;
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
#endif /* !KERNEL */

#if !KERNEL

#define IOUserClient_QueueNames  ""

#define IOUserClient_MethodNames  ""

#define IOUserClientMetaClass_MethodNames  ""

struct OSClassDescription_IOUserClient_t
{
    OSClassDescription base;
    uint64_t           methodOptions[2 * 0];
    uint64_t           metaMethodOptions[2 * 0];
    char               queueNames[sizeof(IOUserClient_QueueNames)];
    char               methodNames[sizeof(IOUserClient_MethodNames)];
    char               metaMethodNames[sizeof(IOUserClientMetaClass_MethodNames)];
};

const struct OSClassDescription_IOUserClient_t
OSClassDescription_IOUserClient =
{
    .base =
    {
        .descriptionSize         = sizeof(OSClassDescription_IOUserClient_t),
        .name                    = "IOUserClient",
        .superName               = "IOService",
        .flags                   = 1*kOSClassCanRemote,
        .methodOptionsSize       = 2 * sizeof(uint64_t) * 0,
        .metaMethodOptionsSize   = 2 * sizeof(uint64_t) * 0,
        .queueNamesSize       = sizeof(IOUserClient_QueueNames),
        .methodNamesSize         = sizeof(IOUserClient_MethodNames),
        .metaMethodNamesSize     = sizeof(IOUserClientMetaClass_MethodNames),
        .methodOptionsOffset     = __builtin_offsetof(struct OSClassDescription_IOUserClient_t, methodOptions),
        .metaMethodOptionsOffset = __builtin_offsetof(struct OSClassDescription_IOUserClient_t, metaMethodOptions),
        .queueNamesOffset     = __builtin_offsetof(struct OSClassDescription_IOUserClient_t, queueNames),
        .methodNamesOffset       = __builtin_offsetof(struct OSClassDescription_IOUserClient_t, methodNames),
        .metaMethodNamesOffset   = __builtin_offsetof(struct OSClassDescription_IOUserClient_t, metaMethodNames),
    },
    .methodOptions =
    {
    },
    .metaMethodOptions =
    {
    },
    .queueNames      = IOUserClient_QueueNames,
    .methodNames     = IOUserClient_MethodNames,
    .metaMethodNames = IOUserClientMetaClass_MethodNames,
};

OSMetaClass * gIOUserClientMetaClass;

static kern_return_t
IOUserClient_New(OSMetaClass * instance);

const OSClassLoadInformation
IOUserClient_Class = 
{
    .version           = 1,
    .description       = &OSClassDescription_IOUserClient.base,
    .instanceSize      = sizeof(IOUserClient),

    .metaPointer       = &gIOUserClientMetaClass,
    .New               = &IOUserClient_New,
};

extern const void * const
gIOUserClient_Declaration;
const void * const
gIOUserClient_Declaration
__attribute__((visibility("hidden"),section("__DATA_CONST,__osclassinfo,regular,no_dead_strip")))
    = &IOUserClient_Class;

static kern_return_t
IOUserClient_New(OSMetaClass * instance)
{
    if (!new(instance) IOUserClientMetaClass) return (kIOReturnNoMemory);
    return (kIOReturnSuccess);
}

kern_return_t
IOUserClientMetaClass::New(OSObject * instance)
{
    if (!new(instance) IOUserClient) return (kIOReturnNoMemory);
    return (kIOReturnSuccess);
}

#endif /* !KERNEL */

kern_return_t
IOUserClient::Dispatch(const IORPC rpc)
{
    return _Dispatch(this, rpc);
}

kern_return_t
IOUserClient::_Dispatch(IOUserClient * self, const IORPC rpc)
{
    kern_return_t ret = kIOReturnUnsupported;
    IORPCMessage * msg = IORPCMessageFromMach(rpc.message, false);

    switch (msg->msgid)
    {
        case IOUserClient__ExternalMethod_ID:
        {
            union {
                kern_return_t (IOUserClient::*fIn)(IOUserClient__ExternalMethod_Args);
                IOUserClient::_ExternalMethod_Handler handler;
            } map;
            map.fIn = &IOUserClient::_ExternalMethod_Impl;
            ret = IOUserClient::_ExternalMethod_Invoke(rpc, self, map.handler);
            break;
        }
#if KERNEL
        case IOUserClient_KernelCompletion_ID:
        {
            union {
                void (IOUserClient::*fIn)(IOUserClient_AsyncCompletion_Args);
                IOUserClient::AsyncCompletion_Handler handler;
            } map;
            map.fIn = &IOUserClient::KernelCompletion_Impl;
            ret = IOUserClient::AsyncCompletion_Invoke(rpc, self, map.handler);
            break;
        }
#endif /* !KERNEL */

        default:
            ret = IOService::_Dispatch(self, rpc);
            break;
    }

    return (ret);
}

#if KERNEL
kern_return_t
IOUserClient::MetaClass::Dispatch(const IORPC rpc)
{
#else /* KERNEL */
kern_return_t
IOUserClientMetaClass::Dispatch(const IORPC rpc)
{
#endif /* !KERNEL */

    kern_return_t ret = kIOReturnUnsupported;
    IORPCMessage * msg = IORPCMessageFromMach(rpc.message, false);

    switch (msg->msgid)
    {

        default:
            ret = OSMetaClassBase::Dispatch(rpc);
            break;
    }

    return (ret);
}

void
IOUserClient::AsyncCompletion(
        OSAction * action,
        IOReturn status,
        const unsigned long long * asyncData,
        uint32_t asyncDataCount,
        OSDispatchMethod supermethod)
{
    kern_return_t ret;
    union
    {
        IOUserClient_AsyncCompletion_Msg msg;
    } buf;
    struct IOUserClient_AsyncCompletion_Msg * msg = &buf.msg;

    memset(msg, 0, sizeof(struct IOUserClient_AsyncCompletion_Msg));
    msg->mach.msgh.msgh_id   = kIORPCVersion190615;
    msg->mach.msgh.msgh_size = sizeof(*msg);
    msg->content.__hdr.flags = 1*kIORPCMessageOneway
                             | 1*kIORPCMessageSimpleReply
                             | 0*kIORPCMessageLocalHost
                             | 0*kIORPCMessageOnqueue;
    msg->content.__hdr.msgid = IOUserClient_AsyncCompletion_ID;
    msg->content.__object = (OSObjectRef) action;
    msg->content.__hdr.objectRefs = IOUserClient_AsyncCompletion_Msg_ObjRefs;
    msg->mach.msgh_body.msgh_descriptor_count = 2;

    msg->__object__descriptor.type = MACH_MSG_PORT_DESCRIPTOR;

    msg->action__descriptor.type = MACH_MSG_PORT_DESCRIPTOR;
    msg->content.action = (OSObjectRef) action;

    msg->content.status = status;

    msg->content.asyncData = asyncData;

    if (asyncDataCount > (sizeof(msg->content.__asyncData) / sizeof(msg->content.__asyncData[0]))) return;
    bcopy(asyncData, &msg->content.__asyncData[0], asyncDataCount * sizeof(msg->content.__asyncData[0]));

    msg->content.asyncDataCount = asyncDataCount;

    IORPC rpc = { .message = &buf.msg.mach, .sendSize = sizeof(*msg), .reply = NULL, .replySize = 0 };
    ret = action->Invoke(rpc);

}

kern_return_t
IOUserClient::CopyClientMemoryForType(
        uint64_t type,
        uint64_t * options,
        IOMemoryDescriptor ** memory,
        OSDispatchMethod supermethod)
{
    kern_return_t ret;
    union
    {
        IOUserClient_CopyClientMemoryForType_Msg msg;
        struct
        {
            IOUserClient_CopyClientMemoryForType_Rpl rpl;
            mach_msg_max_trailer_t trailer;
        } rpl;
    } buf;
    struct IOUserClient_CopyClientMemoryForType_Msg * msg = &buf.msg;
    struct IOUserClient_CopyClientMemoryForType_Rpl * rpl = &buf.rpl.rpl;

    memset(msg, 0, sizeof(struct IOUserClient_CopyClientMemoryForType_Msg));
    msg->mach.msgh.msgh_id   = kIORPCVersion190615;
    msg->mach.msgh.msgh_size = sizeof(*msg);
    msg->content.__hdr.flags = 0*kIORPCMessageOneway
                             | 0*kIORPCMessageSimpleReply
                             | 0*kIORPCMessageLocalHost
                             | 0*kIORPCMessageOnqueue;
    msg->content.__hdr.msgid = IOUserClient_CopyClientMemoryForType_ID;
    msg->content.__object = (OSObjectRef) this;
    msg->content.__hdr.objectRefs = IOUserClient_CopyClientMemoryForType_Msg_ObjRefs;
    msg->mach.msgh_body.msgh_descriptor_count = 1;

    msg->__object__descriptor.type = MACH_MSG_PORT_DESCRIPTOR;

    msg->content.type = type;

    IORPC rpc = { .message = &buf.msg.mach, .sendSize = sizeof(buf.msg), .reply = &buf.rpl.rpl.mach, .replySize = sizeof(buf.rpl) };
    if (supermethod) ret = supermethod((OSObject *)this, rpc);
    else             ret = ((OSObject *)this)->Invoke(rpc);

    if (kIOReturnSuccess == ret)
    do {
        {
            if (rpl->mach.msgh.msgh_size                  != sizeof(*rpl)) { ret = kIOReturnIPCError; break; };
            if (rpl->content.__hdr.msgid                  != IOUserClient_CopyClientMemoryForType_ID) { ret = kIOReturnIPCError; break; };
            if (rpl->mach.msgh_body.msgh_descriptor_count != 1) { ret = kIOReturnIPCError; break; };
            if (IOUserClient_CopyClientMemoryForType_Rpl_ObjRefs   != rpl->content.__hdr.objectRefs) { ret = kIOReturnIPCError; break; };
        }
    }
    while (false);
    if (kIOReturnSuccess == ret)
    {
        if (options) *options = rpl->content.options;
        *memory = OSDynamicCast(IOMemoryDescriptor, (OSObject *) rpl->content.memory);
        if (rpl->content.memory && !*memory) ret = kIOReturnBadArgument;
    }


    return (ret);
}

kern_return_t
IOUserClient::_ExternalMethod(
        uint64_t selector,
        const unsigned long long * scalarInput,
        uint32_t scalarInputCount,
        OSData * structureInput,
        IOMemoryDescriptor * structureInputDescriptor,
        unsigned long long * scalarOutput,
        uint32_t * scalarOutputCount,
        uint64_t structureOutputMaximumSize,
        OSData ** structureOutput,
        IOMemoryDescriptor * structureOutputDescriptor,
        OSAction * completion,
        OSDispatchMethod supermethod)
{
    kern_return_t ret;
    union
    {
        IOUserClient__ExternalMethod_Msg msg;
        struct
        {
            IOUserClient__ExternalMethod_Rpl rpl;
            mach_msg_max_trailer_t trailer;
        } rpl;
    } buf;
    struct IOUserClient__ExternalMethod_Msg * msg = &buf.msg;
    struct IOUserClient__ExternalMethod_Rpl * rpl = &buf.rpl.rpl;

    memset(msg, 0, sizeof(struct IOUserClient__ExternalMethod_Msg));
    msg->mach.msgh.msgh_id   = kIORPCVersion190615;
    msg->mach.msgh.msgh_size = sizeof(*msg);
    msg->content.__hdr.flags = 0*kIORPCMessageOneway
                             | 0*kIORPCMessageSimpleReply
                             | 0*kIORPCMessageLocalHost
                             | 0*kIORPCMessageOnqueue;
    msg->content.__hdr.msgid = IOUserClient__ExternalMethod_ID;
    msg->content.__object = (OSObjectRef) this;
    msg->content.__hdr.objectRefs = IOUserClient__ExternalMethod_Msg_ObjRefs;
    msg->mach.msgh_body.msgh_descriptor_count = 5;

    msg->__object__descriptor.type = MACH_MSG_PORT_DESCRIPTOR;

    msg->content.selector = selector;

    msg->content.scalarInput = scalarInput;

    if (scalarInputCount > (sizeof(msg->content.__scalarInput) / sizeof(msg->content.__scalarInput[0]))) return kIOReturnOverrun;
    bcopy(scalarInput, &msg->content.__scalarInput[0], scalarInputCount * sizeof(msg->content.__scalarInput[0]));

    msg->content.scalarInputCount = scalarInputCount;

    msg->structureInput__descriptor.type = MACH_MSG_OOL_DESCRIPTOR;
    msg->structureInput__descriptor.copy = MACH_MSG_VIRTUAL_COPY;
    msg->structureInput__descriptor.address = (void *) __builtin_offsetof(IOUserClient__ExternalMethod_Msg_Content, structureInput);
    msg->content.structureInput = structureInput;

    msg->structureInputDescriptor__descriptor.type = MACH_MSG_PORT_DESCRIPTOR;
    msg->content.structureInputDescriptor = (OSObjectRef) structureInputDescriptor;

    if (*scalarOutputCount > (sizeof(rpl->content.__scalarOutput) / sizeof(rpl->content.__scalarOutput[0]))) return kIOReturnOverrun;
    msg->content.scalarOutputCount = *scalarOutputCount;

    msg->content.structureOutputMaximumSize = structureOutputMaximumSize;

    msg->structureOutputDescriptor__descriptor.type = MACH_MSG_PORT_DESCRIPTOR;
    msg->content.structureOutputDescriptor = (OSObjectRef) structureOutputDescriptor;

    msg->completion__descriptor.type = MACH_MSG_PORT_DESCRIPTOR;
    msg->content.completion = (OSObjectRef) completion;

    IORPC rpc = { .message = &buf.msg.mach, .sendSize = sizeof(buf.msg), .reply = &buf.rpl.rpl.mach, .replySize = sizeof(buf.rpl) };
    if (supermethod) ret = supermethod((OSObject *)this, rpc);
    else             ret = ((OSObject *)this)->Invoke(rpc);

    if (kIOReturnSuccess == ret)
    do {
        {
            if (rpl->mach.msgh.msgh_size                  != sizeof(*rpl)) { ret = kIOReturnIPCError; break; };
            if (rpl->content.__hdr.msgid                  != IOUserClient__ExternalMethod_ID) { ret = kIOReturnIPCError; break; };
            if (rpl->mach.msgh_body.msgh_descriptor_count != 1) { ret = kIOReturnIPCError; break; };
            if (IOUserClient__ExternalMethod_Rpl_ObjRefs   != rpl->content.__hdr.objectRefs) { ret = kIOReturnIPCError; break; };
        }
    }
    while (false);
    if (kIOReturnSuccess == ret)
    {
        if (rpl->content.scalarOutputCount < *scalarOutputCount) *scalarOutputCount = rpl->content.scalarOutputCount;
        bcopy(&rpl->content.__scalarOutput[0], scalarOutput, *scalarOutputCount * sizeof(rpl->content.__scalarOutput[0]));
        *structureOutput = OSDynamicCast(OSData, (OSObject *) rpl->content.structureOutput);
        if (rpl->content.structureOutput && !*structureOutput) ret = kIOReturnBadArgument;
    }


    return (ret);
}

kern_return_t
IOUserClient::CreateActionKernelCompletion(size_t referenceSize, OSAction ** action)
{
    kern_return_t ret;

    ret = OSAction::Create(this,
                           IOUserClient_KernelCompletion_ID,
                           IOUserClient_AsyncCompletion_ID,
                           referenceSize,
                           action);

    return (ret);
}

kern_return_t
IOUserClient::AsyncCompletion_Invoke(const IORPC _rpc,
        OSMetaClassBase * target,
        AsyncCompletion_Handler func)
{
    IOUserClient_AsyncCompletion_Invocation rpc = { _rpc };
    OSAction * action;
    uint32_t asyncDataCount = (sizeof(rpc.message->content.__asyncData) / sizeof(rpc.message->content.__asyncData[0]));

    if (IOUserClient_AsyncCompletion_Msg_ObjRefs != rpc.message->content.__hdr.objectRefs) return (kIOReturnIPCError);
    action = OSDynamicCast(OSAction, (OSObject *) rpc.message->content.action);
    if (!action && rpc.message->content.action) return (kIOReturnBadArgument);
    if (asyncDataCount > rpc.message->content.asyncDataCount) asyncDataCount = rpc.message->content.asyncDataCount;

    (*func)(target,        
        action,
        rpc.message->content.status,
        &rpc.message->content.__asyncData[0],
        asyncDataCount);


    return (kIOReturnSuccess);
}

kern_return_t
IOUserClient::CopyClientMemoryForType_Invoke(const IORPC _rpc,
        OSMetaClassBase * target,
        CopyClientMemoryForType_Handler func)
{
    IOUserClient_CopyClientMemoryForType_Invocation rpc = { _rpc };
    kern_return_t ret;

    if (IOUserClient_CopyClientMemoryForType_Msg_ObjRefs != rpc.message->content.__hdr.objectRefs) return (kIOReturnIPCError);

    ret = (*func)(target,        
        rpc.message->content.type,
        &rpc.reply->content.options,
        (IOMemoryDescriptor **)&rpc.reply->content.memory);

    if (kIOReturnSuccess != ret) return (ret);

    rpc.reply->content.__hdr.msgid = IOUserClient_CopyClientMemoryForType_ID;
    rpc.reply->content.__hdr.flags = kIORPCMessageOneway;
    rpc.reply->mach.msgh.msgh_id   = kIORPCVersion190615Reply;
    rpc.reply->mach.msgh.msgh_size = sizeof(*rpc.reply);
    rpc.reply->mach.msgh_body.msgh_descriptor_count = 1;
    rpc.reply->content.__hdr.objectRefs = IOUserClient_CopyClientMemoryForType_Rpl_ObjRefs;
    rpc.reply->memory__descriptor.type = MACH_MSG_PORT_DESCRIPTOR;

    return (ret);
}

kern_return_t
IOUserClient::_ExternalMethod_Invoke(const IORPC _rpc,
        OSMetaClassBase * target,
        _ExternalMethod_Handler func)
{
    IOUserClient__ExternalMethod_Invocation rpc = { _rpc };
    kern_return_t ret;
    uint32_t scalarInputCount = (sizeof(rpc.message->content.__scalarInput) / sizeof(rpc.message->content.__scalarInput[0]));
    IOMemoryDescriptor * structureInputDescriptor;
    unsigned int scalarOutputCount = (sizeof(rpc.reply->content.__scalarOutput) / sizeof(rpc.reply->content.__scalarOutput[0]));
    IOMemoryDescriptor * structureOutputDescriptor;
    OSAction * completion;

    if (IOUserClient__ExternalMethod_Msg_ObjRefs != rpc.message->content.__hdr.objectRefs) return (kIOReturnIPCError);
    structureInputDescriptor = OSDynamicCast(IOMemoryDescriptor, (OSObject *) rpc.message->content.structureInputDescriptor);
    if (!structureInputDescriptor && rpc.message->content.structureInputDescriptor) return (kIOReturnBadArgument);
    structureOutputDescriptor = OSDynamicCast(IOMemoryDescriptor, (OSObject *) rpc.message->content.structureOutputDescriptor);
    if (!structureOutputDescriptor && rpc.message->content.structureOutputDescriptor) return (kIOReturnBadArgument);
    completion = OSDynamicCast(OSAction, (OSObject *) rpc.message->content.completion);
    if (!completion && rpc.message->content.completion) return (kIOReturnBadArgument);
    if (scalarInputCount > rpc.message->content.scalarInputCount) scalarInputCount = rpc.message->content.scalarInputCount;
    if (scalarOutputCount > rpc.message->content.scalarOutputCount) scalarOutputCount = rpc.message->content.scalarOutputCount;

    ret = (*func)(target,        
        rpc.message->content.selector,
        &rpc.message->content.__scalarInput[0],
        scalarInputCount,
        rpc.message->content.structureInput,
        structureInputDescriptor,
        &rpc.reply->content.__scalarOutput[0],
        &scalarOutputCount,
        rpc.message->content.structureOutputMaximumSize,
        &rpc.reply->content.structureOutput,
        structureOutputDescriptor,
        completion);

    if (kIOReturnSuccess != ret) return (ret);

    rpc.reply->content.__hdr.msgid = IOUserClient__ExternalMethod_ID;
    rpc.reply->content.__hdr.flags = kIORPCMessageOneway;
    rpc.reply->mach.msgh.msgh_id   = kIORPCVersion190615Reply;
    rpc.reply->mach.msgh.msgh_size = sizeof(*rpc.reply);
    rpc.reply->mach.msgh_body.msgh_descriptor_count = 1;
    rpc.reply->content.__hdr.objectRefs = IOUserClient__ExternalMethod_Rpl_ObjRefs;
    rpc.reply->content.scalarOutputCount = scalarOutputCount;
    rpc.reply->structureOutput__descriptor.type = MACH_MSG_OOL_DESCRIPTOR;
    rpc.reply->structureOutput__descriptor.copy = MACH_MSG_VIRTUAL_COPY;
    rpc.reply->structureOutput__descriptor.address = (void *) __builtin_offsetof(IOUserClient__ExternalMethod_Rpl_Content, structureOutput);
    rpc.reply->structureOutput__descriptor.size = 0;

    return (ret);
}



