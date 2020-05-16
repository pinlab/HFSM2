﻿namespace hfsm2 {
namespace detail {

////////////////////////////////////////////////////////////////////////////////

#ifdef HFSM_EXPLICIT_MEMBER_SPECIALIZATION

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
template <typename T>
T&
OS_<TN_, TA_, NI_, TI_, TR_...>::access() {
	return InitialStates::template contains<T>() ?
		initial  .template access<T>() :
		remaining.template access<T>();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
template <typename T>
const T&
OS_<TN_, TA_, NI_, TI_, TR_...>::access() const {
	return InitialStates::template contains<T>() ?
		initial  .template access<T>() :
		remaining.template access<T>();
}

#endif

//------------------------------------------------------------------------------

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
void
OS_<TN_, TA_, NI_, TI_, TR_...>::wideRegister(Registry& registry,
											  const ForkID forkId)
{
	initial  .deepRegister(registry, Parent{forkId, PRONG_INDEX});
	remaining.wideRegister(registry, forkId);
}

//------------------------------------------------------------------------------

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
bool
OS_<TN_, TA_, NI_, TI_, TR_...>::wideForwardEntryGuard(GuardControl& control,
													   const ProngConstBits prongs)
{
	const bool i = prongs.get(PRONG_INDEX) ?
				   initial  .deepForwardEntryGuard(control) : false;

	const bool r = remaining.wideForwardEntryGuard(control, prongs);

	return i || r;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
bool
OS_<TN_, TA_, NI_, TI_, TR_...>::wideForwardEntryGuard(GuardControl& control) {
	const bool i = initial  .deepForwardEntryGuard(control);
	const bool r = remaining.wideForwardEntryGuard(control);

	return i || r;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
bool
OS_<TN_, TA_, NI_, TI_, TR_...>::wideEntryGuard(GuardControl& control) {
	const bool i = initial  .deepEntryGuard(control);
	const bool r = remaining.wideEntryGuard(control);

	return i || r;
}

//------------------------------------------------------------------------------

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
void
OS_<TN_, TA_, NI_, TI_, TR_...>::wideConstruct(PlanControl& control) {
	initial	 .deepConstruct(control);
	remaining.wideConstruct(control);
}

//------------------------------------------------------------------------------

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
void
OS_<TN_, TA_, NI_, TI_, TR_...>::wideEnter(PlanControl& control) {
	initial  .deepEnter(control);
	remaining.wideEnter(control);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
void
OS_<TN_, TA_, NI_, TI_, TR_...>::wideReenter(PlanControl& control) {
	initial  .deepReenter(control);
	remaining.wideReenter(control);
}

//------------------------------------------------------------------------------

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
Status
OS_<TN_, TA_, NI_, TI_, TR_...>::wideUpdate(FullControl& control) {
	const auto status =	   initial	.deepUpdate(control);
	return combine(status, remaining.wideUpdate(control));
}

//------------------------------------------------------------------------------

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
template <typename TEvent>
Status
OS_<TN_, TA_, NI_, TI_, TR_...>::wideReact(FullControl& control,
									  const TEvent& event)
{
	const auto status =	   initial	.deepReact(control, event);
	return combine(status, remaining.wideReact(control, event));
}

//------------------------------------------------------------------------------

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
bool
OS_<TN_, TA_, NI_, TI_, TR_...>::wideForwardExitGuard(GuardControl& control,
													  const ProngConstBits prongs)
{
	const bool i = prongs.get(PRONG_INDEX) ?
				   initial  .deepForwardExitGuard(control) : false;

	const bool r = remaining.wideForwardExitGuard(control, prongs);

	return i || r;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
bool
OS_<TN_, TA_, NI_, TI_, TR_...>::wideForwardExitGuard(GuardControl& control) {
	const bool i = initial  .deepForwardExitGuard(control);
	const bool r = remaining.wideForwardExitGuard(control);

	return i || r;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
bool
OS_<TN_, TA_, NI_, TI_, TR_...>::wideExitGuard(GuardControl& control) {
	const bool i = initial  .deepExitGuard(control);
	const bool r = remaining.wideExitGuard(control);

	return i || r;
}

//------------------------------------------------------------------------------

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
void
OS_<TN_, TA_, NI_, TI_, TR_...>::wideExit(PlanControl& control) {
	initial	 .deepExit(control);
	remaining.wideExit(control);
}

//------------------------------------------------------------------------------

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
void
OS_<TN_, TA_, NI_, TI_, TR_...>::wideDestruct(PlanControl& control) {
	initial	 .deepDestruct(control);
	remaining.wideDestruct(control);
}

//------------------------------------------------------------------------------

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
void
OS_<TN_, TA_, NI_, TI_, TR_...>::wideForwardActive(Control& control,
												   const Request::Type request,
												   const ProngConstBits prongs)
{
	const Request::Type local = prongs.get(PRONG_INDEX) ?
		request : Request::REMAIN;

	initial	 .deepForwardActive(control, local);
	remaining.wideForwardActive(control, request, prongs);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
void
OS_<TN_, TA_, NI_, TI_, TR_...>::wideForwardRequest(Control& control,
													const Request::Type request,
													const ProngConstBits prongs)
{
	const Request::Type local = prongs.get(PRONG_INDEX) ?
		request : Request::REMAIN;

	initial	 .deepForwardRequest(control, local);
	remaining.wideForwardRequest(control, request, prongs);
}

//------------------------------------------------------------------------------

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
void
OS_<TN_, TA_, NI_, TI_, TR_...>::wideRequestChange(Control& control) {
	initial  .deepRequestChange(control);
	remaining.wideRequestChange(control);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
void
OS_<TN_, TA_, NI_, TI_, TR_...>::wideRequestRemain(Registry& registry) {
	initial	 .deepRequestRemain(registry);
	remaining.wideRequestRemain(registry);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
void
OS_<TN_, TA_, NI_, TI_, TR_...>::wideRequestRestart(Registry& registry) {
	initial	 .deepRequestRestart(registry);
	remaining.wideRequestRestart(registry);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
void
OS_<TN_, TA_, NI_, TI_, TR_...>::wideRequestResume(Registry& registry) {
	initial	 .deepRequestResume(registry);
	remaining.wideRequestResume(registry);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
void
OS_<TN_, TA_, NI_, TI_, TR_...>::wideRequestUtilize(Control& control) {
	initial  .deepRequestUtilize(control);
	remaining.wideRequestUtilize(control);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
void
OS_<TN_, TA_, NI_, TI_, TR_...>::wideRequestRandomize(Control& control) {
	initial  .deepRequestRandomize(control);
	remaining.wideRequestRandomize(control);
}

//------------------------------------------------------------------------------

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
typename TA_::Utility
OS_<TN_, TA_, NI_, TI_, TR_...>::wideReportChange(Control& control) {
	const UP	  i = initial  .deepReportChange(control);
	const Utility r = remaining.wideReportChange(control);

	return i.utility + r;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
typename TA_::Utility
OS_<TN_, TA_, NI_, TI_, TR_...>::wideReportUtilize(Control& control) {
	const UP	  i = initial  .deepReportUtilize(control);
	const Utility r = remaining.wideReportUtilize(control);

	return i.utility + r;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
typename TA_::Utility
OS_<TN_, TA_, NI_, TI_, TR_...>::wideReportRandomize(Control& control) {
	const Utility i = initial  .deepReportRandomize(control);
	const Utility r = remaining.wideReportRandomize(control);

	return i + r;
}

//------------------------------------------------------------------------------

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
void
OS_<TN_, TA_, NI_, TI_, TR_...>::wideChangeToRequested(PlanControl& control) {
	initial	 .deepChangeToRequested(control);
	remaining.wideChangeToRequested(control);
}

//------------------------------------------------------------------------------

#ifdef HFSM_ENABLE_STRUCTURE_REPORT

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
void
OS_<TN_, TA_, NI_, TI_, TR_...>::wideGetNames(const LongIndex parent,
											  const ShortIndex depth,
											  StructureStateInfos& _stateInfos) const
{
	initial	 .deepGetNames(parent, StructureStateInfo::ORTHOGONAL, depth, _stateInfos);
	remaining.wideGetNames(parent,								   depth, _stateInfos);
}

#endif

//------------------------------------------------------------------------------

#ifdef HFSM_ENABLE_SERIALIZATION

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
void
OS_<TN_, TA_, NI_, TI_, TR_...>::wideSaveActive(const Registry& registry,
												WriteStream& stream) const
{
	initial	 .deepSaveActive(registry, stream);
	remaining.wideSaveActive(registry, stream);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
void
OS_<TN_, TA_, NI_, TI_, TR_...>::wideSaveResumable(const Registry& registry,
												   WriteStream& stream) const
{
	initial	 .deepSaveResumable(registry, stream);
	remaining.wideSaveResumable(registry, stream);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
void
OS_<TN_, TA_, NI_, TI_, TR_...>::wideLoadRequested(Registry& registry,
												   ReadStream& stream) const
{
	initial	 .deepLoadRequested(registry, stream);
	remaining.wideLoadRequested(registry, stream);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename TN_, typename TA_, ShortIndex NI_, typename TI_, typename... TR_>
void
OS_<TN_, TA_, NI_, TI_, TR_...>::wideLoadResumable(Registry& registry,
												   ReadStream& stream) const
{
	initial	 .deepLoadResumable(registry, stream);
	remaining.wideLoadResumable(registry, stream);
}

#endif

////////////////////////////////////////////////////////////////////////////////

}
}
